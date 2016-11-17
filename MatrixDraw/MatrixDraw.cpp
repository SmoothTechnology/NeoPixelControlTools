#include "MatrixDraw.h"

MatrixDraw::MatrixDraw()
{
	xSize = 0;
	ySize = 0;
}

MatrixDraw::MatrixDraw(int xAxis, int yAxis)
	: xSize(xAxis)
	, ySize(yAxis)
{
	Canvas = new int*[xAxis];
	for (int i = 0; i < xAxis; ++i)
	    Canvas[i] = new int[yAxis];
}

MatrixDraw::~MatrixDraw()
{

}

void MatrixDraw::DrawLine(int x1, int y1, int x2, int y2, int color)
{
	int dx = x2 - x1;
	int dy = y2 - y1;
	for(int x = x1; x <= x2; x++){
  		int y = y1 + dy * (x - x1) / dx;
  		SetPixelAt(x, y, color);
	}
}

void MatrixDraw::DrawCircle(int r, int cX, int cY, int color)
{
	int x = r;
    int y = 0;
    int err = 0;

    while (x >= y)
    {
        SetPixelAt(cX + x, cY + y, color);
        SetPixelAt(cX + y, cY + x, color);
        SetPixelAt(cX - y, cY + x, color);
        SetPixelAt(cX - x, cY + y, color);
        SetPixelAt(cX - x, cY - y, color);
        SetPixelAt(cX - y, cY - x, color);
        SetPixelAt(cX + y, cY - x, color);
        SetPixelAt(cX + x, cY - y, color);

        y += 1;
        err += 1 + 2*y;
        if (2*(err-x) + 1 > 0)
        {
            x -= 1;
            err += 1 - 2*x;
        }
    }
}

void MatrixDraw::ClearMatrix()
{
	for(int x = 0; x < xSize; x++)
	{
		for(int y = 0; y < ySize; y++)
		{
			Canvas[x][y] = 0;
		}
	}
}