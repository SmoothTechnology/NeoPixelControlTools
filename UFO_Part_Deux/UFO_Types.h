struct Color
{
	Color() {Red = 0; Green = 0; Blue = 0;};
	Color(int r, int g, int b) {Red = r; Green = g; Blue = b;};

	int Red;
	int Green;
	int Blue;
};

struct PatColors
{
	PatColors() {};
	PatColors(Color c1, Color c2) {Color1 = c1; Color2 = c2; };

	Color Color1;

	Color Color2;
};

struct UFOSettings
{
	int rate;
	int brightness;
	int patternID;
	int mappingID;
	PatColors colors;
};