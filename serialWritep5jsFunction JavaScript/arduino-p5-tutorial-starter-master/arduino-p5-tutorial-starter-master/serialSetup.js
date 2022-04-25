function serialSetup(){


	  //set up communication port
	  serial = new p5.SerialPort(); // make a new instance of the serialport library
	  serial.on('list', printList); // set a callback function for the serialport list event
	  serial.on('connected', serverConnected); // callback for connecting to the server
	  serial.on('open', portOpen); // callback for the port opening
	  serial.on('data', serialEvent); // callback for when new data arrives
	  serial.on('error', serialError); // callback for errors
	  serial.on('close', portClose); // callback for the port closing

	  serial.list(); // list the serial ports
	  serial.open(portName); // open a serial port
	}
