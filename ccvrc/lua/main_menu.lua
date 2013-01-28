--require "state";

--addSprite(index, x, y, "src", width, height);
--addStringSprite(index, x, y, size, "string", color);
--addPolySprite(index, color, x1, y1, x2, y2, x2, y2);
--linearInterpolate(index, destinationX, destinationY, speed);
--getProp


addSprite("bg", 0, 0, "main_menu_bg.png", 0, 0);
addSprite("centa", 600, 400, "centa_full.png", 0, 0);
addSprite("russ", 200, 400, "russ_final.png", -674, 0);
addSprite("title", (800 / 2) - (684 / 2), 50, "logo.png", 0, 0);
addStringSprite("cts", 250, 450, 64, "Click to Start", 0xfeffff);

function init()
	
end

function event(target, type)
	if target == "mousedown" or target == "keydown" then
		linearInterpolate("cts", getProp("cts", "x"), 500, 10.0);
	end

	return;
end

function error(type)

end