import jkvasir.math.*;
import jkvasir.engine.*;
import jkvasir.world.*;
import jkvasir.engine.rendering.*;

class Main {
	public static void main(String[] args) {
		Vec3 v = new Vec3();
		v.toString();
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
				mesh.setDiffuseTex(base, 0xffffff);
				Material mat = mesh.getMaterial();
				if (mat == null)
					throw new RenderException("Material was null.");
				System.out.println("Num textures: " + Long.toString(mat.getNumTextures()));
				TextureImage tex = Texture.colourImage(0x80ff09);
				System.out.println("Tex col: " + TextureImage.pixelToRGBA(tex.getPixels()[0]).toString());
				Texture t = new Texture(base);
				t.setTexture(tex);
				mat.setTexture(0, t);
				/////////////////
				while (true) {
					if (time.nextFrameReady()) {
						//////////////// ONUPDATE
						cam.aspect = (float) base.getAspect();
						cam.debugControls(base, time.delta(), 1.4f, 3.f);
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