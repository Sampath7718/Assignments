function validateAll(zForm) {
	if (isEmpty(zForm.Customer.value)) {
		alert ("Error!  Please enter your name.")
		zForm.Customer.focus()
		return false
	}
	if (isEmpty(zForm.Address.value)) {
		alert ("Error!  Please enter your Address.")
		zForm.Customer.focus()
		return false
	}
	if (isEmpty(zForm.City.value)) {
		alert ("Error!  Please enter your City.")
		zForm.Customer.focus()
		return false
	}
	if(noneSelected(zForm.State, true)) {
		alert ("Error!  Please specify your state.")
		zForm.CCexpMo.focus()
		return false
	}
	if (isEmpty(zForm.Zip.value)) {
		alert ("Error!  Please enter your zip code.")
		zForm.Customer.focus()
		return false
	}
	if (isEmpty(zForm.Phone.value)) {
		alert ("Error!  Please enter your phone number!.")
		zForm.Customer.focus()
		return false
	}
	if (isEmpty(zForm.Email.value)) {
		alert ("Error!  Please enter your email.")
		zForm.Customer.focus()
		return false
	}
	if(noneSelected(zForm.CardType, true)) {
		alert ("Error!  Please specify your card type.")
		zForm.CCexpMo.focus()
		return false
	}
	if (isEmpty(zForm.CCnum.value)) {
		alert ("Error!  Please enter your Card num.")
		zForm.Customer.focus()
		return false
	}
	if(noneSelected(zForm.CCexpMo, true)) {
		alert ("Error!  Please specify the month your credit card expires.")
		zForm.CCexpMo.focus()
		return false
	}
	if(noneSelected(zForm.CCexpYr, true)) {
		alert ("Error!  Please specify the year your credit card expires.")
		zForm.CCexpYr.focus()
		return false
	}
	return true
	}
	
	function noneSelected(zSelectList, ckFirst) {
	if(noneSelected.arguments.length == 1) {
		var ckFirst = false
	}
	if(zSelectList.selectedIndex == -1 ||
		(zSelectList.selectedIndex == 0 && ckFirst)) {
		return true
	} else {
		return false
	}
	}
	
	function isEmpty(str) {
	var empty = (str == null || str == "") ? true : false
	return empty
	}
	
	function validZip(zip) {
		var zipRegExp = /^(\d{5}){1}((-\d{4})?)$/	
		if (zipRegExp.test(zip)) {
		
			return true
		} else {
		alert("Not valid zip.") 
			return false
		}
	}

	function validPhone(phone){
	  if( phone.match(/\d/g).length===9){
		return true; 
		} else{
		alert("Enter a 9 digit phone number"); 
	}
	}



	// converts num to Currency format
	// sets showDollarSign to true if you want a 
	// leading $, otherwise sets it to false
	function toCurrency(num, showDollarSign) {
		if(showDollarSign) {
			return "$" + roundFloat(num, 2)
		} else {
			return roundFloat(num, 2)
		}
	}
	
	// rounds a floating-point number to the
	// specified number of decimal places
	// returns the value in string format
	// to hold the decimal places if decimal
	// value is 0
	function roundFloat(num, decimalPlaces) {
		// convert num to a number if not already
		if (isNaN(num)) {
			num = parseFloat(num)
		}

		// multiply num by 10 to the x power, 
		// where x = number of decimalPlaces desired
		var temp = num * Math.pow(10, decimalPlaces)

		// now round to an integer to get rid of 
		// excess digits
		temp = Math.round(temp)

		//convert to a string
		temp = temp.toString()

		// pad numbers that are shorter than the number
		// of decimal points desired with leading zeros
		while (temp.length <= decimalPlaces) {
			temp = "0" + temp
		}

		// determine the index number where the decimal
		// point needs to be inserted and insert it
		var decNdx = temp.length - decimalPlaces
		temp = temp.substring(0, decNdx) + "." +
			   temp.substring(decNdx)
		return temp
	}
	
	// totals the order form
	function totalOrder(zForm) {
		var total = 0
		for (i=1; i<zForm.length-3; i+=2) {
			amt = parseFloat(zForm.elements[i].value)
			if (isNaN(amt)) {
				amt = 0
			}
			total += amt
		}
		zForm.Total.value = toCurrency(total, false)
	}

	// calculates the extended value and
	// updates the total
	function extend(zForm, itemID, price) {
		var itemQty = zForm[itemID + "qty"].value
		if (isNaN(itemQty)) {
			itemQty = parseFloat(itemQty)
		}
		if (isNaN(price)) {
			price = parseFloat(price)
		}
		var ext = itemQty * price
		
		zForm[itemID + "qty"].value = toCurrency(itemQty, false)
		zForm[itemID + "ext"].value = toCurrency(ext, false)
		totalOrder(zForm)
	}