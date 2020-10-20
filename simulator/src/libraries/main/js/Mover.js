'use strict';

class Mover{

	constructor(options){
		this.initialized = false;
		this.$point = $(options.point);
		if(this.$point.length < 1) return;
		this.$wall = this.$point.parents('#wall').first();
		if(this.$wall.length < 1) return;
		this.initialized = true;
		this.position = { x: 0, y: 0 };
		this.wallSize = {
			absolute: { w: 100, h: 100, }
		}
		$(window).on('resize', ()=>{ this.setWallSize(); }).trigger('resize');
	}

	setWallSize(w, h){
		this.wallSize = {
			absolute: {
				w: w ? w : this.wallSize.absolute.w,
				h: h ? h : this.wallSize.absolute.h,
			},
			relative: {
				w: this.$wall.outerWidth(),
				h: this.$wall.outerHeight(),
			}
		};
	}

	setPoint(){
		let absPercX = this.position.x * (this.wallSize.absolute.w / 100);
		let absPercY = this.position.y * (this.wallSize.absolute.h / 100);
		this.$point.css({'left': absPercX + '%', 'top': absPercY + '%'});
		this.$point.find('span').html(this.position.x + ' - ' + this.position.y);
	}

	move(x, y){
		if(!this.initialized) return { x, y };
		if(this.position.x + x > this.wallSize.absolute.w){
			x = x - ((this.position.x + x) - this.wallSize.absolute.w);
		}
		if(this.position.x + x < 0 ) x = 0;
		this.position.x = this.position.x + x;
		if(this.position.y + y > this.wallSize.absolute.h){
			y = y - ((this.position.y + y) - this.wallSize.absolute.h);
		}
		if(this.position.y + y < 0 ) y = 0;
		this.position.y = this.position.y + y;

		this.setPoint();

		return this.position;
	}

}

window.Mover = Mover;
