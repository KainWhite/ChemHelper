#ifndef CHGRAPHICS_H
#define CHGRAPHICS_H

#include <QGraphicsView>
#include <QLabel>

void launchGEditAnimation();
void launchGEditInverseAnimation();
void launchAllAnimation();
void launchAllInverseAnimation();
void setGEditFinishPosition(QGraphicsView &Underscore);
void setGEditStartPosition(QGraphicsView &Underscore);
void setAllFinishPosition(QWidget &GEdit, QLabel &Logo);
void setAllStartPosition(QWidget &GEdit, QLabel &Logo);
void redraw(QWidget &GEdit, QGraphicsView &Underscore, QLabel &Logo);
//void showMessageInvalidInputFormula();


#endif // CHGRAPHICS_H
