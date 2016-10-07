#include <iostream>

#include <cmath>

using namespace std;

int main(){

	const double DEG_TO_RAD = M_PI / 180.0;

	const double mass = 100; //kg
	const double area = 20; //m^2
	const double coeffDrag = 1.2;
	const double airDensity = 1.225; //kg/m^3
	const double gravity = 9.81;
	
	double v0, height, angle, chuteTime, deltaTime;

	cout << "Enter initial velocity, height, launch angle (degrees),"
		 <<	 "time of parachute deployment, time interval: " << endl;
	cin >> v0 >> height >> angle >> chuteTime >> deltaTime;

	double vX = v0 * cos(angle * DEG_TO_RAD);
	double vY0 = -v0 * sin(angle * DEG_TO_RAD);
	double vY = vY0;
	double a = gravity;
	double time = 0;

	while(height > 0){

		cout << "Position (x,y): (" << vX * time << ", " << height << ")\t\tVelocity: " 
			 << sqrt(vX * vX + vY * vY) << "\t\tTime: " << time << endl;

		if(time < chuteTime){
			height -= vY * deltaTime + 0.5 * gravity * deltaTime * deltaTime;
			vY = vY0 + gravity * time;
		}else{
			a = 9.81 - 0.5 * (1 / mass) * airDensity * coeffDrag * area * vY * vY;
			vY += a * deltaTime;
			height -= vY * deltaTime + 0.5 * a * deltaTime * deltaTime;
		}
		time += deltaTime;
	}
}

/*

Output for test case:

Enter initial velocity, height, launch angle (degrees),time of parachute deployment, time interval:
5 100 30 3 0.1
Position (x,y): (0, 100)                Velocity: 5             Time: 0
Position (x,y): (0.433013, 100.201)             Velocity: 5             Time: 0.1
Position (x,y): (0.866025, 100.402)             Velocity: 4.58883               Time: 0.2
Position (x,y): (1.29904, 100.505)              Velocity: 4.36342               Time: 0.3
Position (x,y): (1.73205, 100.51)               Velocity: 4.35273               Time: 0.4
Position (x,y): (2.16506, 100.416)              Velocity: 4.55826               Time: 0.5
Position (x,y): (2.59808, 100.225)              Velocity: 4.95318               Time: 0.6
Position (x,y): (3.03109, 99.9352)              Velocity: 5.49682               Time: 0.7
Position (x,y): (3.4641, 99.5475)               Velocity: 6.14985               Time: 0.8
Position (x,y): (3.89711, 99.0618)              Velocity: 6.88121               Time: 0.9
Position (x,y): (4.33013, 98.4779)              Velocity: 7.66852               Time: 1
Position (x,y): (4.76314, 97.796)               Velocity: 8.49624               Time: 1.1
Position (x,y): (5.19615, 97.0159)              Velocity: 9.35365               Time: 1.2
Position (x,y): (5.62917, 96.1378)              Velocity: 10.2333               Time: 1.3
Position (x,y): (6.06218, 95.1615)              Velocity: 11.1299               Time: 1.4
Position (x,y): (6.49519, 94.0872)              Velocity: 12.0396               Time: 1.5
Position (x,y): (6.9282, 92.9147)               Velocity: 12.9598               Time: 1.6
Position (x,y): (7.36122, 91.6442)              Velocity: 13.8883               Time: 1.7
Position (x,y): (7.79423, 90.2755)              Velocity: 14.8235               Time: 1.8
Position (x,y): (8.22724, 88.8088)              Velocity: 15.7644               Time: 1.9
Position (x,y): (8.66025, 87.2439)              Velocity: 16.7098               Time: 2
Position (x,y): (9.09327, 85.581)               Velocity: 17.6591               Time: 2.1
Position (x,y): (9.52628, 83.8199)              Velocity: 18.6117               Time: 2.2
Position (x,y): (9.95929, 81.9608)              Velocity: 19.5671               Time: 2.3
Position (x,y): (10.3923, 80.0035)              Velocity: 20.525                Time: 2.4
Position (x,y): (10.8253, 77.9482)              Velocity: 21.4849               Time: 2.5
Position (x,y): (11.2583, 75.7947)              Velocity: 22.4466               Time: 2.6
Position (x,y): (11.6913, 73.5432)              Velocity: 23.41         Time: 2.7
Position (x,y): (12.1244, 71.1935)              Velocity: 24.3747               Time: 2.8
Position (x,y): (12.5574, 68.7458)              Velocity: 25.3407               Time: 2.9
Position (x,y): (12.9904, 66.1999)              Velocity: 26.3078               Time: 3
Position (x,y): (13.4234, 64.9426)              Velocity: 17.5736               Time: 3.1
Position (x,y): (13.8564, 63.7319)              Velocity: 14.4143               Time: 3.2
Position (x,y): (14.2894, 62.6267)              Velocity: 12.7112               Time: 3.3
Position (x,y): (14.7224, 61.5994)              Velocity: 11.6658               Time: 3.4
Position (x,y): (15.1554, 60.6277)              Velocity: 10.9785               Time: 3.5
Position (x,y): (15.5885, 59.6961)              Velocity: 10.5071               Time: 3.6
Position (x,y): (16.0215, 58.7937)              Velocity: 10.1745               Time: 3.7
Position (x,y): (16.4545, 57.9128)              Velocity: 9.93524               Time: 3.8
Position (x,y): (16.8875, 57.0478)              Velocity: 9.76065               Time: 3.9
Position (x,y): (17.3205, 56.1946)              Velocity: 9.63194               Time: 4
Position (x,y): (17.7535, 55.3503)              Velocity: 9.53634               Time: 4.1
Position (x,y): (18.1865, 54.5126)              Velocity: 9.46494               Time: 4.2
Position (x,y): (18.6195, 53.6801)              Velocity: 9.41138               Time: 4.3
Position (x,y): (19.0526, 52.8513)              Velocity: 9.37108               Time: 4.4
Position (x,y): (19.4856, 52.0253)              Velocity: 9.34069               Time: 4.5
Position (x,y): (19.9186, 51.2016)              Velocity: 9.31772               Time: 4.6
Position (x,y): (20.3516, 50.3795)              Velocity: 9.30035               Time: 4.7
Position (x,y): (20.7846, 49.5586)              Velocity: 9.28719               Time: 4.8
Position (x,y): (21.2176, 48.7387)              Velocity: 9.27721               Time: 4.9
Position (x,y): (21.6506, 47.9195)              Velocity: 9.26965               Time: 5
Position (x,y): (22.0836, 47.1009)              Velocity: 9.26391               Time: 5.1
Position (x,y): (22.5167, 46.2827)              Velocity: 9.25955               Time: 5.2
Position (x,y): (22.9497, 45.4648)              Velocity: 9.25624               Time: 5.3
Position (x,y): (23.3827, 44.6471)              Velocity: 9.25373               Time: 5.4
Position (x,y): (23.8157, 43.8296)              Velocity: 9.25182               Time: 5.5
Position (x,y): (24.2487, 43.0123)              Velocity: 9.25037               Time: 5.6
Position (x,y): (24.6817, 42.195)               Velocity: 9.24927               Time: 5.7
Position (x,y): (25.1147, 41.3779)              Velocity: 9.24844               Time: 5.8
Position (x,y): (25.5477, 40.5608)              Velocity: 9.2478                Time: 5.9
Position (x,y): (25.9808, 39.7437)              Velocity: 9.24732               Time: 6
Position (x,y): (26.4138, 38.9267)              Velocity: 9.24695               Time: 6.1
Position (x,y): (26.8468, 38.1097)              Velocity: 9.24667               Time: 6.2
Position (x,y): (27.2798, 37.2927)              Velocity: 9.24646               Time: 6.3
Position (x,y): (27.7128, 36.4757)              Velocity: 9.2463                Time: 6.4
Position (x,y): (28.1458, 35.6588)              Velocity: 9.24618               Time: 6.5
Position (x,y): (28.5788, 34.8418)              Velocity: 9.24609               Time: 6.6
Position (x,y): (29.0119, 34.0249)              Velocity: 9.24602               Time: 6.7
Position (x,y): (29.4449, 33.208)               Velocity: 9.24596               Time: 6.8
Position (x,y): (29.8779, 32.3911)              Velocity: 9.24592               Time: 6.9
Position (x,y): (30.3109, 31.5741)              Velocity: 9.24589               Time: 7
Position (x,y): (30.7439, 30.7572)              Velocity: 9.24587               Time: 7.1
Position (x,y): (31.1769, 29.9403)              Velocity: 9.24585               Time: 7.2
Position (x,y): (31.6099, 29.1234)              Velocity: 9.24584               Time: 7.3
Position (x,y): (32.0429, 28.3065)              Velocity: 9.24583               Time: 7.4
Position (x,y): (32.476, 27.4895)               Velocity: 9.24582               Time: 7.5
Position (x,y): (32.909, 26.6726)               Velocity: 9.24581               Time: 7.6
Position (x,y): (33.342, 25.8557)               Velocity: 9.24581               Time: 7.7
Position (x,y): (33.775, 25.0388)               Velocity: 9.2458                Time: 7.8
Position (x,y): (34.208, 24.2219)               Velocity: 9.2458                Time: 7.9
Position (x,y): (34.641, 23.405)                Velocity: 9.2458                Time: 8
Position (x,y): (35.074, 22.5881)               Velocity: 9.2458                Time: 8.1
Position (x,y): (35.507, 21.7711)               Velocity: 9.2458                Time: 8.2
Position (x,y): (35.9401, 20.9542)              Velocity: 9.2458                Time: 8.3
Position (x,y): (36.3731, 20.1373)              Velocity: 9.2458                Time: 8.4
Position (x,y): (36.8061, 19.3204)              Velocity: 9.24579               Time: 8.5
Position (x,y): (37.2391, 18.5035)              Velocity: 9.24579               Time: 8.6
Position (x,y): (37.6721, 17.6866)              Velocity: 9.24579               Time: 8.7
Position (x,y): (38.1051, 16.8697)              Velocity: 9.24579               Time: 8.8
Position (x,y): (38.5381, 16.0528)              Velocity: 9.24579               Time: 8.9
Position (x,y): (38.9711, 15.2358)              Velocity: 9.24579               Time: 9
Position (x,y): (39.4042, 14.4189)              Velocity: 9.24579               Time: 9.1
Position (x,y): (39.8372, 13.602)               Velocity: 9.24579               Time: 9.2
Position (x,y): (40.2702, 12.7851)              Velocity: 9.24579               Time: 9.3
Position (x,y): (40.7032, 11.9682)              Velocity: 9.24579               Time: 9.4
Position (x,y): (41.1362, 11.1513)              Velocity: 9.24579               Time: 9.5
Position (x,y): (41.5692, 10.3344)              Velocity: 9.24579               Time: 9.6
Position (x,y): (42.0022, 9.51745)              Velocity: 9.24579               Time: 9.7
Position (x,y): (42.4352, 8.70054)              Velocity: 9.24579               Time: 9.8
Position (x,y): (42.8683, 7.88363)              Velocity: 9.24579               Time: 9.9
Position (x,y): (43.3013, 7.06671)              Velocity: 9.24579               Time: 10
Position (x,y): (43.7343, 6.2498)               Velocity: 9.24579               Time: 10.1
Position (x,y): (44.1673, 5.43289)              Velocity: 9.24579               Time: 10.2
Position (x,y): (44.6003, 4.61597)              Velocity: 9.24579               Time: 10.3
Position (x,y): (45.0333, 3.79906)              Velocity: 9.24579               Time: 10.4
Position (x,y): (45.4663, 2.98215)              Velocity: 9.24579               Time: 10.5
Position (x,y): (45.8993, 2.16523)              Velocity: 9.24579               Time: 10.6
Position (x,y): (46.3324, 1.34832)              Velocity: 9.24579               Time: 10.7
Position (x,y): (46.7654, 0.531408)             Velocity: 9.24579               Time: 10.8

*/