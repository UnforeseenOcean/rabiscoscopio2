#include "topimage.h"

TopImage::TopImage(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);
	hide();
}

TopImage::~TopImage()
{

}

void TopImage::paintEvent(QPaintEvent *)
{
     QPainter painter(this);
     //painter.setPen(Qt::blue);
     //painter.setFont(QFont("Arial", 30));
     //painter.drawText(rect(), Qt::AlignCenter, "Qt");
	
	double w = width();
	double h = height();
	//TCanvas * can = imgMain->Picture->Bitmap->Canvas;
	//imgMain->Picture->Bitmap->Width = w;
	//imgMain->Picture->Bitmap->Height = h;

	painter.setPen(Qt::black);
	painter.setBrush(Qt::black);
	QRect rectangle(0,0,w,h);
	painter.drawRect(rectangle);

	painter.setPen(Qt::darkGreen);
	painter.drawLine(QLine(0, h/2, w, h/2));
	painter.drawLine(QLine(w/2, 0, w/2, h));

	painter.setPen(Qt::green);
	
	double x, y;
	if (points.size() > 0) {
		x = points.at(0).x;
		x = x * w/100 + w/2;
		y = points.at(0).y;
		y = y * h/100 + h/2;

		QPainterPath path;
		path.moveTo(x, y);
		//painter.moveTo(x, y);
		for (unsigned int i = 1; i < points.size(); i++) {
			x = points.at(i).x;
			x = x * w/100 + w/2;
			y = points.at(i).y;
			y = y * h/100 + h/2;
			path.lineTo(x, y);
		}
		painter.drawPath(path);
	}
}

/*void TopImage::RefreshPoints(vector <TVecPoint> points)
{
}*/
