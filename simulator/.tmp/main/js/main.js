'use strict';

;

(function ($) {
  var mover = new Mover({
    point: '#point'
  });
  var interval, lastPosition;
  $(document).ready(function () {
    interval = setInterval(function () {
      var position = mover.move(10, 2);

      if (lastPosition && lastPosition.x == position.x && lastPosition.y == position.y) {
        clearInterval(interval);
      } else {
        lastPosition = {
          x: position.x,
          y: position.y
        };
        console.log(position);
      }
    }, 300);
  });
})(jQuery);
//# sourceMappingURL=main.js.map