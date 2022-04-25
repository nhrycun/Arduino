


// Following functions print the serial communication status to the console for debugging purposes
function printList(portList) {
	// portList is an array of serial port names
	for (var i = 0; i < portList.length; i++) {
	  // Display the list the console:
	  print(i + " " + portList[i]);
	}
  }

  function serverConnected() {
	print('connected to server.');
  }

  function portOpen() {
	print('the serial port opened.')
  }

  function serialEvent() {
	inData = Number(serial.read());
  }

  function serialError(err) {
	print('Something went wrong with the serial port. ' + err);
  }

  function portClose() {
	print('The serial port closed.');
  }


