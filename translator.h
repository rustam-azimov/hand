#ifndef TRANSLATOR_H
#define TRANSLATOR_H

#include <QObject>
#include <QList>

/**
* @file translator.h
*
* Implementation of the class Translator.
* It is the main class of the programm.
* It is connects all the components of the program.
*/

class FileActionPerformer;
class FileUserPerformer;
class GloveInterface;
class HandInterface;
class User;
class GloveCalibrator;
class KalmanFilter;

enum ConnectionType {
	noConnection = 0,
	gloveToHand = 1,
	actionToHand = 2,
	calibrate = 3
};

class Translator :  public QObject
{
	Q_OBJECT
public:
	Translator();
	~Translator();

	/// Try to connect hardware glove.
	void connectGlove(const QString &portName);
	/// Try to connect hardware hand.
	void connectHand(const QString &portName);

	/// Returns true, if the glove is connected.
	bool isGloveConnected() const;
	/// Return true, if the glove port is open.
	bool isGloveDataSending() const;
	/// Returns true, if the glove is connected.
	bool isHandConnected() const;

	/// Esteblishes a connection of components, described in the current connection type.
	void startConnection();
	/// Stops all connections.
	void stopConnection();

	/// Returns an list of the last read data.
	QList<int> sensorData() { return mSensorDatas; }
	/// Returns an list of the last read and filtred data.
	QList<int> filteredSensorData() {return mFiltredDatas; }
	/// Returns an list of the last converted to hand data.
	QList<int> convertedData() { return mConvertedDatas; }

	QList<int> sensorsMin() const;
	QList<int> sensorsMax() const;

	bool isCalibrateing() const { return mConnectionType == calibrate; }

	/// Stops all connections, and set current connection type = type.
	void setConnectionType(ConnectionType const& type);
	/// Return current connection type.
	ConnectionType connectionType() const { return mConnectionType; }

	/**
	 * Starts loading action from the file.
	 * Sets current connection type = actionToHand.
	 * Start to send data to the hand.
	 */
	void startLoadAction(const QString &fileName);
	/// Stops loading action and set current connection type = noConnection.
	void stopLoadAction();

	/// Starts saving action to the file. Saves converted to hand data.
	void startSaveAction(const QString &fileName, const int &freq);
	/// Stops saving action and set current connection type = noConnection.
	void stopSaveAction();

	/// Sets connection type = calibrate and start to calibrate glove.
	void startCalibrate();

public slots:
	void stopCalibrate();

protected slots:
	void convertData();
	void filterData();
	void sendDataToCalibrator();

signals:
	/// Emited, when the translator recieves new data from the glove.
	void dataIsRead();
	void loadingStoped();

protected:
	void saveConvertedData(QList<int> const& data);
	void saveSensorsData(QList<int> const& data);

	int map(int const& value
			, int const& min, int const& max);

	void sendDataToHand();

private:
	ConnectionType mConnectionType;

	QList<int> mConvertedDatas;
	QList<int> mSensorDatas;
	QList<int> mFiltredDatas;

	User *mUser;

	FileActionPerformer *mFileActionPerformer;
	FileUserPerformer *mFileUserPerformer;
	GloveCalibrator *mGloveCalibrator;

	GloveInterface *mGloveInterface;
	HandInterface *mHandInterface;

	KalmanFilter *mKalmanFilter;
};

#endif // TRANSLATOR_H
