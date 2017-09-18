#pragma once
#ifndef GRAPHICPROXY_H
#define GRAPHICPROXY_H
#include "Graphic.h"
#include "IGraphic.h"

class GraphicProxy : public IGraphic {
public:
	GraphicProxy();
	~GraphicProxy();
	void Draw();
private:
	Graphic* graphic;
	Graphic* getInstance(void);
};

#endif