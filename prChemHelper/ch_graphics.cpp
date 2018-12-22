#include <windows.h>

#include "ch_graphics.h"
#include "ch_variables_and_types.h"


int SysTimeToInt(SYSTEMTIME x)
{
    return ((x.wHour * 60 + x.wMinute) * 60 + x.wSecond) * 1000 + x.wMilliseconds;
}

void LaunchEditAnimation()
{
    SYSTEMTIME UTC;
    if (!WasEditAnimation)
    {
        GetSystemTime(&UTC);
        EditAnimationRunning = true;
        TimeEditAnimationStart = SysTimeToInt(UTC);
        WasEditAnimation = true;
    }
}
void LaunchEditInverseAnimation()
{
    SYSTEMTIME UTC;
    if (WasEditAnimation)
    {
        GetSystemTime(&UTC);
        EditInverseAnimationRunning = true;
        TimeEditInverseAnimationStart = SysTimeToInt(UTC);
        WasEditAnimation = false;
        //Form1.FocusControl(NULL);
    }
}

void LaunchAllAnimation()
{
    SYSTEMTIME UTC;
    if (!WasAllAnimation)
    {
        GetSystemTime(&UTC);
        AllAnimationRunning = true;
        TimeAllAnimationStart = SysTimeToInt(UTC);
        WasAllAnimation = true;
    }
}
void LaunchAllInverseAnimation()
{
    SYSTEMTIME UTC;
    if (WasAllAnimation)
    {
        GetSystemTime(&UTC);
        AllInverseAnimationRunning = true;
        TimeAllInverseAnimationStart = SysTimeToInt(UTC);
        WasAllAnimation = false;
    }
}

/*void SetEditFinishPosition(QLineEdit )
{
    shpLine.Left = edtInputFormula.Left;
    shpLine.Width = edtInputFormula.Width;
}

void SetEditStartPosition()
{
    shpLine.Left = edtInputFormula.Left + edtInputFormula.Width div 2;
    shpLine.Width = 0;
}

void Redraw()
{
  SYSTEMTIME UTC;
  int Now = 0;
  GetSystemTime(&UTC);
  Now = SysTimeToInt(UTC);
  //# with Form1 do
  {
    if ( EditAnimationRunning )
        if ( Now - TimeEditAnimationStart <= EditAnimationTime / 2 )
            shpLine.Left = edtInputFormula.Left + edtInputFormula.Width / 2 - EditLineAcceleration * Sqr( Now - TimeEditAnimationStart ) / 2;
        else
            shpLine.Left = edtInputFormula.Left + EditLineAcceleration * Sqr( TimeEditAnimationStart + EditAnimationTime - Now ) / 2;
    if ( EditInverseAnimationRunning )
        if ( Now - TimeEditInverseAnimationStart < EditAnimationTime / 2 )
            shpLine.Left = edtInputFormula.Left + EditLineAcceleration * Sqr( Now - TimeEditInverseAnimationStart ) / 2;
        else
            shpLine.Left = edtInputFormula.Left + edtInputFormula.Width / 2 - EditLineAcceleration * Sqr( TimeEditInverseAnimationStart + EditAnimationTime - Now ) / 2;
    if ( AllAnimationRunning )
        if ( Now - TimeAllAnimationStart <= AllAnimationTime / 2 )
        {
            edtInputFormula.Left = EditStartPosition.Left + EditLeftAcceleration * Sqr( Now - TimeAllAnimationStart ) / 2;
            edtInputFormula.Top = EditStartPosition.Top + EditTopAcceleration * Sqr( Now - TimeAllAnimationStart ) / 2;
            shpLine.Left = edtInputFormula.Left;
            strngrdSearchResults.Height = SGAcceleration * Sqr( Now - TimeAllAnimationStart ) / 2;
            imgHeader.Left = ImageStartPosition.Left + ImageLeftAcceleration * Sqr( Now - TimeAllAnimationStart ) / 2;
            imgHeader.Top = ImageStartPosition.Top + ImageTopAcceleration * Sqr( Now - TimeAllAnimationStart ) / 2;
        }
        else
        {
            edtInputFormula.Left = EditFinishPosition.Left - EditLeftAcceleration * Sqr( TimeAllAnimationStart + AllAnimationTime - Now ) / 2;
            edtInputFormula.Top = EditFinishPosition.Top - EditTopAcceleration * Sqr( TimeAllAnimationStart + AllAnimationTime - Now ) / 2;
            shpLine.Left = edtInputFormula.Left;
            strngrdSearchResults.Height = SGBottomFinishPosition.Top - SGBottomStartPosition.Top - SGAcceleration * Sqr( TimeAllAnimationStart + AllAnimationTime - Now ) / 2;
            imgHeader.Left = ImageFinishPosition.Left - ImageLeftAcceleration * Sqr( TimeAllAnimationStart + AllAnimationTime - Now ) / 2;
            imgHeader.Top = ImageFinishPosition.Top - ImageTopAcceleration * Sqr( TimeAllAnimationStart + AllAnimationTime - Now ) / 2;
        }
    if ( AllInverseAnimationRunning )
        if ( Now - TimeAllInverseAnimationStart <= AllAnimationTime / 2 )
        {
            edtInputFormula.Left = EditFinishPosition.Left + EditLeftAcceleration * Sqr( Now - TimeAllInverseAnimationStart ) / 2;
            edtInputFormula.Top = EditFinishPosition.Top + EditTopAcceleration * Sqr( Now - TimeAllInverseAnimationStart ) / 2;
            shpLine.Left = edtInputFormula.Left;
            strngrdSearchResults.Height = SGBottomFinishPosition.Top - SGBottomStartPosition.Top - SGAcceleration * Sqr( Now - TimeAllInverseAnimationStart ) / 2;
            imgHeader.Left = ImageStartPosition.Left + ImageLeftAcceleration * Sqr( Now - TimeAllInverseAnimationStart ) / 2;
            imgHeader.Top = ImageStartPosition.Top + ImageTopAcceleration ) * Sqr( Now - TimeAllInverseAnimationStart ) / 2;
        }
        else
        {
            edtInputFormula.Left = EditFinishPosition.Left - EditLeftAcceleration * Sqr( TimeAllInverseAnimationStart + AllAnimationTime - Now ) / 2;
            edtInputFormula.Top = EditFinishPosition.Top - EditTopAcceleration * Sqr( TimeAllInverseAnimationStart + AllAnimationTime - Now ) / 2;
            shpLine.Left = edtInputFormula.Left;
            strngrdSearchResults.Height = - SGAcceleration * Sqr( TimeAllInverseAnimationStart + AllAnimationTime - Now ) / 2;
            imgHeader.Left = ImageFinishPosition.Left - ImageLeftAcceleration * Sqr( TimeAllInverseAnimationStart + AllAnimationTime - Now ) / 2;
            imgHeader.Top = ImageFinishPosition.Top - ImageTopAcceleration * Sqr( TimeAllInverseAnimationStart + AllAnimationTime - Now ) / 2;
        }
    shpLine.Width = edtInputFormula.Width - 2 * ( shpLine.Left - edtInputFormula.Left );
    shpLine.Top = edtInputFormula.Top + edtInputFormula.Height;
    imgSearchButton.Left = edtInputFormula.Left + edtInputFormula.Width + 10;
    imgSearchButton.Top = edtInputFormula.Top;
    }
}


void ShowMessageInvalidInputFormula()
{
  //# with Form1 do
  {
    imgInvalidFormula.Top = edtInputFormula.Top + edtInputFormula.Height + shpLine.Height + 3;
    imgInvalidFormula.Left = edtInputFormula.Left + 30;
    imgInvalidFormula.Visible = true;
  }
}*/
