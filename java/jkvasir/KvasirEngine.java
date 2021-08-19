package jkvasir;

import jkvasir.engine.FrameManager;
import jkvasir.engine.rendering.RenderBase;
import jkvasir.engine.KvasirException;

public abstract class KvasirEngine {
	public FrameManager time = new FrameManager(60);
	public FrameManager fixedTime = new FrameManager(10);
	public RenderBase base = null;

	public KvasirEngine(RenderBase.Type type) {
		base = new RenderBase(type);
	}

	protected void start(String name, int width, int height) throws KvasirException {
		if (!base.init(name, width, height))
			throw new KvasirException("Render base failed to initialize.");
		if (!onStart())
			throw new KvasirException("Method onStart returned false.");
		time.nextFrameReady();
		fixedTime.nextFrameReady();

		while (true) {
			if (time.nextFrameReady()) {
				base.pollEvents();
				onUpdate();
				if (base.shouldClose())
					break;
			}
			if (fixedTime.nextFrameReady())
				onFixedUpdate();
			perFrame();
		}
		onClose();
	}

	/**
	 * Override this to add additional update loops.
	 */
	protected void perFrame() throws KvasirException {
	}

	public void destroyBase() {
		if (base == null)
			return;
		base.destroy();
		base = null;
	}

	public abstract void start() throws KvasirException;

	protected abstract boolean onStart() throws KvasirException;

	protected abstract void onUpdate() throws KvasirException;

	protected abstract void onClose() throws KvasirException;

	protected abstract void onFixedUpdate() throws KvasirException;
}
