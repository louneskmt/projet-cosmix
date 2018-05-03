function getDatas() {
    $.ajax({
        type: "POST",   
        url: "PHP/database_com.php",
	dataType: "html",
        success: function(text) {
	    document.getElementById("_Datas").innerHTML = text;
            setTimeout(getDatas, 1);
        }
    })
}

getDatas();
