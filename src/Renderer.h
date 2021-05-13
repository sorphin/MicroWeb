#pragma once

class App;
struct Widget;

class Renderer
{
public:
	Renderer(App& inApp);

	void Scroll(int delta);

	void OnPageWidgetsLoaded(Widget* widget, int count);
	void RedrawScrollBar();

	Widget* PickPageWidget(int x, int y);
	bool IsOverPageWidget(Widget* widget, int x, int y);

	void DrawStatus(const char* status);

private:
	void RenderWidget(Widget* widget);
	int GetMaxScrollPosition();

	App& app;
	int scrollPosition;
	int pageTopWidgetIndex;
	const char* oldStatus;
};

