package jkvasir;

import jkvasir.engine.FrameManager;
import jkvasir.engine.rendering.RenderBase;
import jkvasir.engine.rendering.RenderException;

public abstract class KvasirEngine {
	public FrameManager time = new FrameManager(60);
	public FrameManager fixedTime = new FrameManager(10);
	public RenderBase base = null;

	public KvasirEngine(RenderBase.Type type) {
		base = new RenderBase(type);
	}

	protected void start(String name, int width, int height) throws RenderException {
		if (!base.init(name, width, height))
			throw new RenderException("Render base failed to initialize.");
		if (!onStart())
			throw new RenderException("Method onStart returned false.");
		time.nextFrameReady();
		fixedTime.nextFrameReady();
		while (true) {
			if (time.nextFrameReady()) {
				base.pollEvents();
				onUpdate();
			}
			if (fixedTime.nextFrameReady()) {
				onFixedUpdate();
				if (base.shouldClose())
					break;
			}
		}
		onClose();
	}

	public abstract void start() throws RenderException;

	protected abstract boolean onStart() throws RenderException;

	protected abstract void onUpdate() throws RenderException;

	protected abstract void onClose() throws RenderException;

	protected abstract void onFixedUpdate() throws RenderException;
}
