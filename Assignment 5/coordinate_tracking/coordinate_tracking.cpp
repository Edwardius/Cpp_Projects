#define _USE_MATH_DEFINES

#include <iostream>
#include <cstdlib>
#include <fstream>
#include <cmath>

using namespace std;

int main()
{
	ifstream droneIn("drone_directions.txt");
	if (!droneIn) {
		cout << "File Not Found\n";
		return EXIT_FAILURE;
	}

	double referenceAngle = 0, angle = 0, distance = 0, pointX = 0, pointY = 0, changeX = 0, changeY = 0;

	while (droneIn >> angle) {
		droneIn >> distance;
		angle = angle / 180;
		referenceAngle += angle;
		changeX = distance * cos(referenceAngle * M_PI);
		changeY = distance * sin(referenceAngle * M_PI);
		//cout << "referenceAngle " << referenceAngle << endl;
		//cout << "changeX " << changeX << endl;
		//cout << "changeY " << changeY << endl;
		pointX += changeX;
		pointY += changeY;
	}

	cout << "(" << pointX << ", " << pointY << ")\n";

	droneIn.close();
	
	return 0;
}

