/*
 Name:		Sortieren.ino
 Created:	09.11.2018 21:58:23
 Author:	Johannes
*/

int arr[10];

// the setup function runs once when you press reset or power the board
void setup() {
	Serial.begin(9600);
}

// the loop function runs over and over again until power down or reset
bool stop = false;
void loop() {
	if (stop) return;
	randomArray();
	for (int x = 0; x < (sizeof(arr) / sizeof(int)); x++) { //Ausgabe des Arrays
		Serial.println();
		Serial.print("VORHER [");
		Serial.print(x);
		Serial.print("] -> ");
		Serial.print(arr[x]);
	}

	Serial.println();

	sortArray();

	for (int x = 0; x < (sizeof(arr) / sizeof(int)); x++) { //Ausgabe des Arrays
		Serial.println();
		Serial.print("NACHER{ ");
		Serial.print(x);
		Serial.print("] -> ");
		Serial.print(arr[x]);
	}
	stop = true;
}

void randomArray() {
	for (int x = 0; x < (sizeof(arr) / sizeof(int)); x++) {
		arr[x] = random(0, 100);
	}
}

void sortArray() {
	for (int x = 0; x < (sizeof(arr) / sizeof(int)); x++) {
		for (int y = 0; y < (sizeof(arr) / sizeof(int)); y++) {
			int arr1 = arr[y];
			int arr2 = arr[y + 1];

			if (arr1 < arr2) {
				arr[y] = arr2;
				arr[y + 1] = arr1;
			}

		}
	}
}
