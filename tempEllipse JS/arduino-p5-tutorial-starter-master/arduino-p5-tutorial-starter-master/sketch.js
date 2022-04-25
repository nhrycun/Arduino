/*
References for these codes:
https://itp.nyu.edu/physcomp/labs/labs-serial-communication/lab-serial-input-to-the-p5-js-ide/
https://itp.nyu.edu/physcomp/labs/labs-serial-communication/lab-serial-input-to-the-p5-js-ide/
*/

var serial; // variable to hold an instance of the serialport library
var portName = 'COM3'; // fill in your serial port name here
var inData; // variable to hold the input data from Arduino

var minWidth = 600; //set min width and height for canvas
var minHeight = 400;
var width, height; // actual width and height for the sketch

var serialSetup;


function setup() {
	serialSetup();
	if (window.innerWidth > minWidth) {
		width = window.innerWidth;
	} else {
		width = minWidth;
	}
	if (window.innerHeight > minHeight) {
		height = window.innerHeight;
	} else {
		height = minHeight;
	}

	//set up canvas
	createCanvas(width, height);
	noStroke();


}

function draw() {
	background(0);


	// TEST
	console.log(inData);

	if (inData > 10 && inData < 25) {
		fill(255);
		textSize(32);
		text("Hello World!", width / 2 - 50, height / 2);
		fill(120, 120, 120, 150)
		ellipse(width / 2, height / 2, inData * 50, inData * 50);
	}
	if (inData < 0.5) {
		fill(255);
		textSize(32);
		text("Goodbye World!", width / 2 - 50, height / 2);
		fill(120, 120, 120, 100)
		ellipse(width / 2, height / 2, inData * 50, inData * 50);
	}
	if (inData > 25) {
		fill(255, 255, 255);
		textSize(32);
		text("Drink your Coffee!", width / 2 - 50, height / 2);
		fill(255, 120, 120, 200)
		ellipse(width / 2, height / 2, inData * 50, inData * 50);
		nofill();
	}



}
