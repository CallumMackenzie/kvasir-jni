import jkvasir.math.*;
import jkvasir.engine.*;
import jkvasir.world.*;
import jkvasir.engine.rendering.*;

class Main {
	public static void main(String[] args) {
		FrameManager time = new FrameManager(60);
		RenderBase base = new RenderBase(RenderBase.Type.OPENGL);
		if (base.init("JKvasir", 480, 360)) {
			try {
				///////////////// ONSTART
				base.setClearColour(0xafbfcf);
				base.depthBufferActive(true);

				Camera3D cam = new Camera3D();
				cam.getPos().setZ(-4);
				Shader shader = Shader.default3D(base);
				Mesh3D mesh = new Mesh3D();
				if (!mesh.loadFromObj(base, "D:\\3D Models\\isont.obj"))
					throw new RenderException("Mesh could not be loaded.");
				/////////////////
				while (true) {
					if (time.nextFrameReady()) {
						//////////////// ONUPDATE
						cam.aspect = (float)base.getAspect();
						base.clear();
						base.renderMesh3D(cam, mesh, shader);
						base.swapBuffers();
						////////////////
					}
					base.pollEvents();
					if (base.shouldClose())
						break;
				}
			} catch (RenderException e) {
				e.printStackTrace();
			}
		}
	}
}