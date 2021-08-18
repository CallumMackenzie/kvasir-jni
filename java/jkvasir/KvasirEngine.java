package jkvasir;

import jkvasir.engine.FrameManager;
import jkvasir.engine.rendering.RenderBase;
import jkvasir.engine.rendering.RenderException;

public abstract class KvasirEngine {
	public FrameManager time = new FrameManager(60);
	public RenderBase base;

	public KvasirEngine(RenderBase.Type type) {
		base = new RenderBase(type);
	}

	protected void start(String name, int width, int height) throws RenderException {
		if (!base.init(name, width, height))
			throw new RenderException("Render base failed to initialize.");
		if (!onStart())
			throw new RenderException("Method onStart returned false.");
		while (true) {
			if (time.nextFrameReady()) {
				onUpdate();
				if (base.shouldClose())
					break;
			}
			base.pollEvents();
		}
		onClose();
	}

	public abstract void start() throws RenderException;

	protected abstract boolean onStart() throws RenderException;

	protected abstract void onUpdate();

	protected abstract void onClose();
}
