var i = 1;
var g = 0;
var loc = location.href;
var datasOffset = document.getElementById('_Datas').offsetTop; 

function parallax() {
	var header = document.getElementById('header');
	header.style.backgroundPosition = "0px "+(-30-window.pageYOffset/30)+"vh";
	header.style.filter = "blur("+(window.pageYOffset/100)+"px)";
}

function scroll() {
	if (i == 1) {
 		if(window.pageYOffset > -1 && window.pageYOffset < 100) {
			location.href = "#_Datas";
			history.replaceState(null, null, loc);
			i = 0;
		}
		
		if(window.pageYOffset < (1.10*datasOffset) && window.pageYOffset > (0.90*datasOffset)) {
			location.href = "#header";
			history.replaceState(null, null, loc);
			i = 0;
		}
	}
	g = 1;
}

window.addEventListener("scroll", parallax, false);
window.addEventListener("scroll", scroll, false);
