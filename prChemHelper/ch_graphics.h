#ifndef CHGRAPHICS_H
#define CHGRAPHICS_H

#include <QGraphicsView>
#include <QLabel>
#include <QLayout>
#include <QTableWidget>

void setGEditFinishPosition(QGraphicsView &Underscore);
void setGEditStartPosition(QGraphicsView &Underscore);
void setAllFinishPosition(QWidget &GEdit, QLabel &Logo, QTableWidget &SearchResults);
void setAllStartPosition(QWidget &GEdit, QLabel &Logo, QTableWidget &SearchResults);
void redraw(QWidget &GEdit, QGraphicsView &Underscore, QLabel &Logo, QTableWidget &SearchResults);
//void showMessageInvalidInputFormula();


#endif // CHGRAPHICS_H
