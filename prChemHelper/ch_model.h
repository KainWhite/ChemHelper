#ifndef CH_MODEL_H
#define CH_MODEL_H

#include <string>
#include <QTextEdit>
#include <QGraphicsView>
#include <QLabel>
#include <QTableWidget>

std::string normallize(const std::string &inputFormula);
bool isValidChemical(const std::string &someFormula );

void gEditFocusIn(QTextEdit &edtInputFormula);
void gEditFocusOut(QTextEdit &edtInputFormula);

void launchGEditAnimation();
void launchGEditInverseAnimation();

void launchAllAnimation();
void launchAllInverseAnimation();


void gEditAnimationFinished(QGraphicsView &Underscore);
void gEditInverseAnimationFinished(QGraphicsView &Underscore);

void allAnimationFinished(QWidget &GEdit, QLabel &Logo, QTableWidget &SearchResults);
void allInverseAnimationFinished(QWidget &GEdit, QLabel &Logo, QTableWidget &SearchResults);

void needRedraw(QWidget &GEdit, QGraphicsView &Underscore, QLabel &Logo, QTableWidget &SearchResults);

void initializeVariables(QWidget &GEdit, QGraphicsView &Underscore, QLabel &Logo, QTableWidget &SearchResults);

#endif // A_H
