#ifndef GRAPHICALWIDGET_H
#define GRAPHICALWIDGET_H

#include <QWidget>
#include <QComboBox>
#include <QCheckBox>
#include "plotWidget.h"

class GraphicalWidget : public QWidget
{
	Q_OBJECT
public:
	GraphicalWidget(const int &countOfSensors);

	void updateOriginalPoint(const int &newPoint);
	void updateFilteredPoint(const int &newPoint);

	void updateFilteredVisible(bool isVisible);

	int getIndexOfCurrentSensor();

private slots:

	void changedNumberOfSensor(const int &newSensor);

	void changedFilteredStatus(bool newStatus);

private:

	PlotWidget *mPlotWidget;

	QComboBox *mCurrentSensor;

	QCheckBox *filteredDataStatus;

	int mIndexOfCurrentSensor;
};

#endif // GRAPHICALWIDGET_H
