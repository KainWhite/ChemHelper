#include <windows.h>

#include "ch_graphics.h"
#include "ch_variables_and_types.h"


void launchGEditAnimation()
{
    SYSTEMTIME UTC;
    if (!WasGEditAnimation)
    {
        GetSystemTime(&UTC);
        GEditAnimationRunning = true;
        TimeGEditAnimationStart = sysTimeToInt(UTC);
        WasGEditAnimation = true;
    }
}
void launchGEditInverseAnimation()
{
    SYSTEMTIME UTC;
    if (WasGEditAnimation)
    {
        GetSystemTime(&UTC);
        GEditInverseAnimationRunning = true;
        TimeGEditInverseAnimationStart = sysTimeToInt(UTC);
        WasGEditAnimation = false;
        //Form1.FocusControl(NULL);
    }
}

void launchAllAnimation()
{
    SYSTEMTIME UTC;
    if (!WasAllAnimation)
    {
        GetSystemTime(&UTC);
        AllAnimationRunning = true;
        TimeAllAnimationStart = sysTimeToInt(UTC);
        WasAllAnimation = true;
    }
}
void launchAllInverseAnimation()
{
    SYSTEMTIME UTC;
    if (WasAllAnimation)
    {
        GetSystemTime(&UTC);
        AllInverseAnimationRunning = true;
        TimeAllInverseAnimationStart = sysTimeToInt(UTC);
        WasAllAnimation = false;
    }
}

void setGEditFinishPosition(QGraphicsView &Underscore)
{
    Underscore.setGeometry(0, 0, EdtInputFormulaWidth, 4);
}

void setGEditStartPosition(QGraphicsView &Underscore)
{
    Underscore.setGeometry(0, 0, 0, 4);
}

void setAllFinishPosition(QWidget &GEdit, QLabel &Logo)
{
    GEdit.move(GEditFinishPosition.left, GEditFinishPosition.top);
    Logo.move(LogoFinishPosition.left, GEditFinishPosition.top);
}
void setAllStartPosition(QWidget &GEdit, QLabel &Logo)
{
    GEdit.move(GEditStartPosition.left, GEditStartPosition.top);
    Logo.move(LogoStartPosition.left, LogoStartPosition.top);
}

void redraw(QWidget &GEdit, QGraphicsView &Underscore, QLabel &Logo)
{
    SYSTEMTIME UTC;
    int now = 0;
    GetSystemTime(&UTC);
    now = sysTimeToInt(UTC);
    if (GEditAnimationRunning)
        if (now - TimeGEditAnimationStart <= GEditAnimationTime / 2)
            Underscore.setGeometry(0, 0, GEditUnderscoreAcceleration * sqr(now - TimeGEditAnimationStart ), 4);
        else
            Underscore.setGeometry(0, 0, EdtInputFormulaWidth - GEditUnderscoreAcceleration * sqr(TimeGEditAnimationStart + GEditAnimationTime - now), 4);
    if (GEditInverseAnimationRunning)
        if (now - TimeGEditInverseAnimationStart < GEditAnimationTime / 2)
            Underscore.setGeometry(0, 0, EdtInputFormulaWidth - GEditUnderscoreAcceleration * sqr(now - TimeGEditInverseAnimationStart ), 4);
        else
            Underscore.setGeometry(0, 0, GEditUnderscoreAcceleration * sqr(TimeGEditInverseAnimationStart + GEditAnimationTime - now ), 4);
    if (AllAnimationRunning)
        if (now - TimeAllAnimationStart <= AllAnimationTime / 2)
        {
            GEdit.move(GEditStartPosition.left + GEditLeftAcceleration * sqr(now - TimeAllAnimationStart) / 2,
                       GEditStartPosition.top + GEditTopAcceleration * sqr(now - TimeAllAnimationStart) / 2);
            //strngrdSearchResults.Height = SGAcceleration * Sqr( Now - TimeAllAnimationStart ) / 2;
            Logo.move(LogoStartPosition.left + LogoLeftAcceleration * sqr(now - TimeAllAnimationStart) / 2,
                      LogoStartPosition.top + LogoTopAcceleration * sqr(now - TimeAllAnimationStart) / 2);
        }
        else
        {
            GEdit.move(GEditFinishPosition.left - GEditLeftAcceleration * sqr(TimeAllAnimationStart + AllAnimationTime - now) / 2,
                       GEditFinishPosition.top - GEditTopAcceleration * sqr(TimeAllAnimationStart + AllAnimationTime - now) / 2);
            //strngrdSearchResults.Height = SGBottomFinishPosition.Top - SGBottomStartPosition.Top - SGAcceleration * Sqr( TimeAllAnimationStart + AllAnimationTime - Now ) / 2;
            Logo.move(LogoFinishPosition.left - LogoLeftAcceleration * sqr(TimeAllAnimationStart + AllAnimationTime - now) / 2,
                      LogoFinishPosition.top - LogoTopAcceleration * sqr(TimeAllAnimationStart + AllAnimationTime - now) / 2);
        }
    if (AllInverseAnimationRunning)
        if (now - TimeAllInverseAnimationStart <= AllAnimationTime / 2)
        {
            GEdit.move(GEditFinishPosition.left + GEditLeftAcceleration * sqr(now - TimeAllInverseAnimationStart) / 2,
                       GEditFinishPosition.top + GEditTopAcceleration * sqr(now - TimeAllInverseAnimationStart) / 2);
            //strngrdSearchResults.Height = SGBottomFinishPosition.Top - SGBottomStartPosition.Top - SGAcceleration * Sqr( Now - TimeAllInverseAnimationStart ) / 2;
            Logo.move(LogoStartPosition.left + LogoLeftAcceleration * sqr(now - TimeAllInverseAnimationStart) / 2,
                      LogoStartPosition.top + LogoTopAcceleration * sqr(now - TimeAllInverseAnimationStart) / 2);
        }
        else
        {
            GEdit.move(GEditFinishPosition.left - GEditLeftAcceleration * sqr(TimeAllInverseAnimationStart + AllAnimationTime - now) / 2,
                       GEditFinishPosition.top - GEditTopAcceleration * sqr(TimeAllInverseAnimationStart + AllAnimationTime - now) / 2);
            //strngrdSearchResults.Height = - SGAcceleration * Sqr( TimeAllInverseAnimationStart + AllAnimationTime - Now ) / 2;
            Logo.move(LogoFinishPosition.left - LogoLeftAcceleration * sqr(TimeAllInverseAnimationStart + AllAnimationTime - now) / 2,
                      LogoFinishPosition.top - LogoTopAcceleration * sqr(TimeAllInverseAnimationStart + AllAnimationTime - now) / 2);
        }
}


/*void ShowMessageInvalidInputFormula()
{
  //# with Form1 do
  {
    imgInvalidFormula.Top = edtInputFormula.Top + edtInputFormula.Height + shpLine.Height + 3;
    imgInvalidFormula.Left = edtInputFormula.Left + 30;
    imgInvalidFormula.Visible = true;
  }
}*/
