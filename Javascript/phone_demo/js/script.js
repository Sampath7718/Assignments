
function validateAll(zForm) {

//validation for phone select list
if(noneSelected(zForm.Phone, true)) {
		alert ("Error!  Please specify your Phone choice.")
		zForm.CCexpMo.focus()
		return false
	}
//validation for color select list
if(noneSelected(zForm.Color, true)) {
		alert ("Error!  Please specify your color choice.")
		zForm.CCexpMo.focus()
		return false
	}
	
}
//validation for radio buttons
function noneSelected(zSelectList, ckFirst) {
	if(noneSelected.arguments.length == 1) {
		var ckFirst = false
	}
}

//whenever a value is changed, print it to the console so it's easy to track/debug what is happening
function logSelected(zSelectList){
console.log(zSelectList.value); 
}


//jquery image picker based on color dropdown

var imagesArray = [
  "gray.png", // represents val 0,
  "silver.png", // 1,
  "gold.png" // 2 ...
];

//changes image when value in color select menu changes 
$('#Color').change(function(){
  
  if(this.value==""){
	//set a default so the form doesn't get messed up after a switch back to default select menu value
	$('#image')[0].src = imagesArray[0];
  }
  else{
  $('#image')[0].src = imagesArray[this.value];
  console.log(imagesArray[this.value]); 

  //remove and re-add zoom to update image
  $('#zoomPhone').trigger('zoom.destroy'); 
  $('#zoomPhone').zoom();
  }
  
});

//use the jquery zoom plugin to zoom the hovered image
$(document).ready(function(){
			$('#zoomPhone').zoom();
		});
