#include <iostream>
#include "MatrixDraw.h"
using namespace std;

struct ExpectedValue
{
	std::string valueName;
	int expectedValue;
	int actualValue;
};

void OnSuccess(std::string testName)
{
	cout << testName << ": " << "Passed" << endl;
}

void OnFailure(std::string testName)
{
	cout << testName << ": " << "Failed" << endl;
}

void ListExpected(ExpectedValue value)
{
	cout << "    " << value.valueName << " - Expected: " << value.expectedValue << " Found: " << value.actualValue << endl;
}

void CheckResults(std::string testName, ExpectedValue valueList [], int numberOfValues)
{
	for(int i = 0; i < numberOfValues; i++)
	{
		if(valueList[i].expectedValue != valueList[i].actualValue)
		{
			OnFailure(testName);

			for(int j = 0; j < numberOfValues; j++)
			{
				ListExpected(valueList[j]);
			}

			return;
		}
	}

	OnSuccess(testName);
}

void DrawMatrix(MatrixDraw &draw)
{
	for(int y = 0; y < draw.GetMatrixYSize(); y++)
	{
		for(int x = 0; x < draw.GetMatrixXSize(); x++)
		{
			if(draw.GetValueAt(x,y) > 0)
			{
				cout << " x";
			}
			else
			{
				cout << "  ";
			}
		}
		cout << endl;
	}
}

void TestConstructor()
{
	std::string testName = "Matrix Constructor";

	MatrixDraw draw(10,20);

	ExpectedValue valueList [2];
	valueList[0].valueName = "Matrix X Size";
	valueList[0].expectedValue = 10;
	valueList[0].actualValue = draw.GetMatrixXSize();

	valueList[1].valueName = "Matrix Y Size";
	valueList[1].expectedValue = 20;
	valueList[1].actualValue = draw.GetMatrixYSize();

	CheckResults(testName, valueList, 2);
}

void TestCanvasAccessor()
{
	std::string testName = "Canvas Accessor";

	MatrixDraw draw(10,20);
	draw.SetPixelAt(5,10, 0xFFA0E1);

	ExpectedValue valueList [1];
	valueList[0].valueName = "Value at 5,10";
	valueList[0].expectedValue = 0xFFA0E1;
	valueList[0].actualValue = draw.GetValueAt(5, 10);

	CheckResults(testName, valueList, 1);
}

void TestClearMatrix()
{
	std::string testName = "Clear Matrix Test";

	MatrixDraw draw(10,20);
	draw.SetPixelAt(5,10, 0xFFA0E1);

	ExpectedValue valueList [2];
	valueList[0].valueName = "Value at 5,10 Before Clear";
	valueList[0].expectedValue = 0xFFA0E1;
	valueList[0].actualValue = draw.GetValueAt(5, 10);

	draw.ClearMatrix();

	valueList[1].valueName = "Value at 5,10 After Clear";
	valueList[1].expectedValue = 0;
	valueList[1].actualValue = draw.GetValueAt(5, 10);

	CheckResults(testName, valueList, 2);
}

int main(void)
{
	cout << "Test Beginning" << endl;

	TestConstructor();
	TestCanvasAccessor();
	TestClearMatrix();

	return 0;
}