# SonicEye
Helmet to be worn by blind individuals to help them detect their surroundings.
# Components
Arduino Uno, Ultrasonic HC-SR04 Sensors, Mini Metal Speaker, Jumper Wire/Breadboard
# How It Works
The sensors are placed equidistantly with a 180 degree view and based on where the closest object is, a tone will play in either the left or right ear of the wearer to indicate where danger is. Depending on the closeness of an approachingobject, a frequency will be played. A high frequency indicates a close object, and a low frequency indicates a far object. 
# Function
The code is split into three main functions: storeDistance, distanceAnalysis, playSound. storeDistance stores the values detected by all of the ultrasonic sensors into an array. distanceAnalysis identifies the lowest distance value detected in the storeDistance functions to see which sensor is picking up the closest sound. playSound maps the lowest distance to a frequency to play a tone on the speaker. To prevent the program from using more memory in the arduino, rather than hard coding a table to map different distances to different frequencies, we used a sigmoid function. This function automatically maps a given range of frequencies (0 to 4000 Hz in our case) to a full input domain. In the particular function we have defined, a theoretical distance of 0 cm would yield a 3600 Hz, which is approximately an A7.
