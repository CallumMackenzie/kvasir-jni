import jkvasir.math.*;
import jkvasir.engine.*;
import jkvasir.world.*;
import jkvasir.engine.rendering.*;

class Main {
	public static void main(String[] args) {
		FrameManager time = new FrameManager(60);
		RenderBase base = new RenderBase(RenderBase.Type.OPENGL);
		if (base.init("JKvasir", 480, 360)) {
			///////////////// ONSTART
			base.setClearColour(0xafbfcf);
			/////////////////
			while (true) {
				if (time.nextFrameReady()) {
					//////////////// ONUPDATE
					base.clear();
					base.swapBuffers();
					////////////////
				}
				base.pollEvents();
				if (base.shouldClose())
					break;
			}
		}
	}
}