'use strict';

function _classCallCheck(instance, Constructor) { if (!(instance instanceof Constructor)) { throw new TypeError("Cannot call a class as a function"); } }

function _defineProperties(target, props) { for (var i = 0; i < props.length; i++) { var descriptor = props[i]; descriptor.enumerable = descriptor.enumerable || false; descriptor.configurable = true; if ("value" in descriptor) descriptor.writable = true; Object.defineProperty(target, descriptor.key, descriptor); } }

function _createClass(Constructor, protoProps, staticProps) { if (protoProps) _defineProperties(Constructor.prototype, protoProps); if (staticProps) _defineProperties(Constructor, staticProps); return Constructor; }

var Mover = /*#__PURE__*/function () {
  function Mover(options) {
    var _this = this;

    _classCallCheck(this, Mover);

    this.initialized = false;
    this.$point = $(options.point);
    if (this.$point.length < 1) return;
    this.$wall = this.$point.parents('#wall').first();
    if (this.$wall.length < 1) return;
    this.initialized = true;
    this.position = {
      x: 0,
      y: 0
    };
    this.wallSize = {
      absolute: {
        w: 100,
        h: 100
      }
    };
    $(window).on('resize', function () {
      _this.setWallSize();
    }).trigger('resize');
  }

  _createClass(Mover, [{
    key: "setWallSize",
    value: function setWallSize(w, h) {
      this.wallSize = {
        absolute: {
          w: w ? w : this.wallSize.absolute.w,
          h: h ? h : this.wallSize.absolute.h
        },
        relative: {
          w: this.$wall.outerWidth(),
          h: this.$wall.outerHeight()
        }
      };
    }
  }, {
    key: "setPoint",
    value: function setPoint() {
      var absPercX = this.position.x * (this.wallSize.absolute.w / 100);
      var absPercY = this.position.y * (this.wallSize.absolute.h / 100);
      this.$point.css({
        'left': absPercX + '%',
        'top': absPercY + '%'
      });
      this.$point.find('span').html(this.position.x + ' - ' + this.position.y);
    }
  }, {
    key: "move",
    value: function move(x, y) {
      if (!this.initialized) return {
        x: x,
        y: y
      };

      if (this.position.x + x > this.wallSize.absolute.w) {
        x = x - (this.position.x + x - this.wallSize.absolute.w);
      }

      if (this.position.x + x < 0) x = 0;
      this.position.x = this.position.x + x;

      if (this.position.y + y > this.wallSize.absolute.h) {
        y = y - (this.position.y + y - this.wallSize.absolute.h);
      }

      if (this.position.y + y < 0) y = 0;
      this.position.y = this.position.y + y;
      this.setPoint();
      return this.position;
    }
  }]);

  return Mover;
}();

window.Mover = Mover;
//# sourceMappingURL=Mover.js.map