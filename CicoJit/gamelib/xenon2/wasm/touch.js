(function() {
	// Set up the canvas
	var canvas = document.querySelector("canvas");

	// Set up mouse events for drawing
	var drawing = false;
	var mousePos = { x:0, y:0 };
	var lastPos = mousePos;
	canvas.addEventListener("mousedown", function (e) {
	        window.onPress(getMousePos(canvas, e));
	}, false);
	canvas.addEventListener("mouseup", function (e) {
	        window.onRelease(getMousePos(canvas, e));
	}, false);
	canvas.addEventListener("mousemove", function (e) {
	        window.onMove(getMousePos(canvas, e));
	}, false);

	// Set up touch events for mobile, etc
	canvas.addEventListener("touchstart", function (e) {
		mousePos = getTouchPos(canvas, e);
		var touch = e.touches[0];
		var mouseEvent = new MouseEvent("mousedown", {
			clientX: touch.clientX,
			clientY: touch.clientY
		});
		canvas.dispatchEvent(mouseEvent);
                e.preventDefault(); 
	}, false);
	canvas.addEventListener("touchend", function (e) {
		var mouseEvent = new MouseEvent("mouseup", {});
		canvas.dispatchEvent(mouseEvent);
                e.preventDefault(); 
	}, false);
	canvas.addEventListener("touchmove", function (e) {
		var touch = e.touches[0];
		var mouseEvent = new MouseEvent("mousemove", {
			clientX: touch.clientX,
			clientY: touch.clientY
		});
		canvas.dispatchEvent(mouseEvent);
                e.preventDefault(); 
	}, false);

	// Prevent scrolling when touching the canvas
	document.body.addEventListener("touchstart", function (e) {
		if (e.target == canvas) {
			e.preventDefault();
		}
	}, false);
	document.body.addEventListener("touchend", function (e) {
		if (e.target == canvas) {
			e.preventDefault();
		}
	}, false);
	document.body.addEventListener("touchmove", function (e) {
		if (e.target == canvas) {
			e.preventDefault();
		}
	}, false);

	// Get the position of the mouse relative to the canvas
	function getMousePos(canvasDom, mouseEvent) {
		var rect = canvasDom.getBoundingClientRect();
                var kx = canvasDom.clientWidth/canvasDom.width;
                var ky = canvasDom.clientHeight/canvasDom.height;
		return {
			x: (mouseEvent.clientX - rect.left)/kx,
			y: (mouseEvent.clientY - rect.top)/ky
		};
	}

	// Get the position of a touch relative to the canvas
	function getTouchPos(canvasDom, touchEvent) {
		var rect = canvasDom.getBoundingClientRect();
                var kx = canvasDom.clientWidth/canvasDom.width;
                var ky = canvasDom.clientHeight/canvasDom.height;
		return {
			x: (touchEvent.touches[0].clientX - rect.left)/kx,
			y: (touchEvent.touches[0].clientY - rect.top)/ky
		};
	}


// 
var mousePos = null;
window.onPress = (p) => {
  mousePos = p;
  if (!game.memoryBuffer)
    return;
  game.memoryBuffer[0x28530 + 0x8f5b] = 0xff;
  game.memoryBuffer[0x28530 + 0x8f59] |= 0x80;
}
window.onRelease = (p) => {
  mousePos = null;
  if (!game.memoryBuffer)
    return;
  game.memoryBuffer[0x28530 + 0x8f5b] = 0;
  game.memoryBuffer[0x28530 + 0x8f59] = 0;
}
window.onMove = (p) => {
  if (mousePos)
    mousePos = p;
}

setInterval( () =>
{
  if (!game.HEAP32)
    return;
  if (!mousePos)
    return;

  var memory16get = (addr) => game.memoryBuffer[addr]+game.memoryBuffer[addr+1]*256;
  var shx = memory16get(0x28530 + 40704+18);  
  var shy = memory16get(0x28530 + 40704+22);  
  if (shx != 0 || shy != 0)
  {
    if (mousePos.x < shx - 10)
      game.memoryBuffer[0x28530 + 0x8f59] |= 4;
    else if (mousePos.x > shx + 10)
      game.memoryBuffer[0x28530 + 0x8f59] |= 8;
    else
      game.memoryBuffer[0x28530 + 0x8f59] &= ~(4|8);

    if (mousePos.y < shy - 10)
      game.memoryBuffer[0x28530 + 0x8f59] |= 1;
    else if (mousePos.y > shy + 10)
      game.memoryBuffer[0x28530 + 0x8f59] |= 2;
    else   
      game.memoryBuffer[0x28530 + 0x8f59] &= ~(1|2);
  }
}, 50);

})();