// Script 10.3 - os.js
// This script creates two linked select menus.

// Establish functionality on window load:
window.onload = function() {
    'use strict';

	// Create the Ajax object:
	var ajax = getXMLHttpRequestObject();
	
	// Function to be called when the readyState changes:
	ajax.onreadystatechange = function() {

		// Check the readyState property:
		if (ajax.readyState == 4) {
		
			// Check the status code:
		    if ( (ajax.status >= 200 && ajax.status < 300) 
		    || (ajax.status == 304) ) {

				// Parse the response:
				var data = JSON.parse(ajax.responseText);

				// Update the page:
				var string;
				string = '\n'; 
				var output = document.getElementById('quote');
				if (output.textContent !== undefined) {
				   // output.textContent = ("$" + data[0].l +", Exchange: " + data[0].e);
						for (var key in data) {
						   if (data.hasOwnProperty(key)) {
							  var obj = data[key];
							  for (var prop in obj) {
								 if (obj.hasOwnProperty(prop)) {
									string += '\n' + (prop + ": " + obj[prop]) ;
								 }
							  }
						   }
						}
						output.innerText = (data[0].l + ", Exchange: " + data[0].e + string); 
				} else {
				    output.innerText = data[0];
				}
			
		    } // End of status IF.
				
		} // End of readyState IF.

	}; // End of onreadystatechange function.
	
	// Fetch the initial data:
	ajax.open('GET', 'resources/quote.php', true);
	ajax.send(null);
	
	// Use a timer to fetch the data again:
	var stockTimer = setInterval(function() {
	
	    ajax.open('GET', 'resources/quote.php', true);
		ajax.send(null);
	
	}, 60000);
		
    
}; // End of onload anonymous function.