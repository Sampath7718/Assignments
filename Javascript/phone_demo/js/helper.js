window.onload = function() 
{
    'use strict';
	// Create the Ajax object to be used for the exchange of data
	var ajax = getXMLHttpRequestObject();
    
	// Set up call back function for the readyState changes
   // note: using an anonymous function vs. 
   //        from the example ajax.onreadystatechange = handleAjaxResponse;
	ajax.onreadystatechange = function() 
	{
     if (ajax.readyState == 4) 
	    {
		    if ( (ajax.status >= 200 && ajax.status < 300) 
		                         || (ajax.status == 304) ) 
  	  { 
				var data = ajax.responseText;
				var str = '  ';
				str += data + '<br>';
    		           document.getElementById('output').innerHTML = str;
		    } else { // Status error!
				document.getElementById('output').innerHTML = 'Error: ' + ajax.statusText;
		    } // if ajax.status
		} // End of if readyState ==4
	}; // End of onreadystatechange anonymous function.
   
   
   // Now add an event handler for the form's submission which will collect the data
    // Replaces handler established by html as 
    // 'onsubmit="processForm();return false;"'
	
    document.getElementById('InForm').onsubmit = function() 
	{
     console.log("processing form data");     
	 //get the elements from the html 
     var select1 = document.getElementById("Phone");
	 var select2= document.getElementById("Color"); 
     var x = document.getElementsByName("shipping");
     var i;
	 //get the value on the radio group that is selected
     var radioGrp=' ';
     for (i = 0; i < x.length; i++) {
          if (x[i].checked) {
             radioGrp =  x[i].value;
          }
      }
	  //array to represent corresponding id numbers and colors
	  var colorArray = [
	  "Space Gray", // represents val 0,
	  "Silver", // 1,
	  "Gold" // 2 ...
	   ];
	  //set up array for reference to correlate id number to phone name 
	  var phoneArray = [
	  "iPhone 5", // represents val 0,
	  "iPhone 6", // 1,
	  "iPhone 6 Plus" // 2 ...
	];
      var data = //"name="        + encodeURIComponent(name) + 
                 "Phone= "   + encodeURIComponent(phoneArray[select1.value]) +"\n"+
                 "Color: " + encodeURIComponent(colorArray[select2.value]) + "\n"+
				 "Shipping: " + encodeURIComponent(radioGrp) ; 
      console.log(data);
      document.getElementById('output').innerText = 'Testing' + data
    	// Open the request:
		ajax.open('POST', 'final.php', true);
		ajax.setRequestHeader('Content-Type', 'application/x-www-form-urlencoded');
		ajax.send(data);
		return false;
	}; // End of onsubmit function.
	
}; // End of onload function.