'use strict';

;(function($){

	const mover = new Mover({point: '#point'});

	let interval, lastPosition;
	$(document).ready(()=>{
		interval = setInterval(()=>{
			let position = mover.move(10, 2);
			if(lastPosition && lastPosition.x == position.x && lastPosition.y == position.y ){
				clearInterval(interval);
			}else{
				lastPosition = { x: position.x , y: position.y };
				console.log(position);
			}
		}, 300);
	});



}(jQuery));
