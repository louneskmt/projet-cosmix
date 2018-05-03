var Trame;
var Last;

function getLog() {
	$.ajax({
		url: 'Resources/Data.txt',
		dataType: 'text',
		success: function(text) {
			Trame = text.split(",");
			if(Trame[3].parseInt - Last.split(",")[3].parseInt >= 1000) {
				
			}
			$("#_Datas").text(text);
			Trame = text;
			setTimeout(getLog, 0.8);
		}
	})
}

getLog();
