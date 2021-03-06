#define sq(x) (x * x)

typedef struct{
	float x, y;
} v2;

task main(){
	const float radius = 0.5f;
	const float width = 89;
	const float height = 80;
	const int numDest = 4;

	v2 start = {width * 0.5f, height * 0.5f};
	v2 startLengths = {
		sqrt(sq(start.x) + sq(height - start.y)), 
		sqrt(sq(width - start.x) + sq(height - start.y))
	};
	v2 dests[numDest];
	displayString(0, "(%d, %d)", start.x, start.y);

	for(int i = 0; i < numDest; i++){
		dests[i].x = (float) (random(89));
		dests[i].y = (float) (random(80));
		displayString(i+1, "(%d, %d)", dests[i].x, dests[i].y);

		nMotorEncoder[motorA] = 0;
		nMotorEncoder[motorC] = 0;

		float dist1 = sqrt(sq(dests[i].x) + sq(height - dests[i].y)) 
		 			- startLengths.x; 
		float dist2 = sqrt(sq(width - dests[i].x) 
					+ sq(height - dests[i].y)) - startLengths.y;

		start = {dests[i].x, dests[i].y};
		startLengths = {
			sqrt(sq(start.x) + sq(height - start.y)), 
			sqrt(sq(width - start.x) + sq(height - start.y))
		};

		int enc1 = 180.f/(PI * radius) * dist1;
		int enc2 = 180.f/(PI * radius) * dist2;

		motor[motorA] = 50 * (int)(abs(dist1)/dist1);
		while(nMotorEncoder[motorA] < (enc1 - 5) ||
			  nMotorEncoder[motorA] > (enc1 + 5)){}
		motor[motorA] = 0;

		motor[motorC] = 50 * (int)(abs(dist2)/dist2);
		while(nMotorEncoder[motorC] < (enc2 - 5) ||
			  nMotorEncoder[motorC] > (enc2 + 5)){}
		motor[motorC] = 0;

		wait1Msec(4000);
	}

}