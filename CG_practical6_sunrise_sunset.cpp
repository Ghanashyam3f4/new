#include <QApplication>
#include <QGraphicsView>
#include <QGraphicsScene>
#include <QGraphicsEllipseItem>
#include <QGraphicsRectItem>
#include <QTimeLine>
#include <QGraphicsItemAnimation>
#include <QPushButton>

int main(int argc, char *argv[])
{
  QApplication app(argc, argv);

  // create the graphics view and scene
  QGraphicsView view;
  QGraphicsScene scene;
  view.setScene(&scene);

  // create the sky rectangle
  QGraphicsRectItem *sky = scene.addRect(0, 0, 400, 200);
  sky->setBrush(QBrush(QColor(0, 191, 255)));

  // create the sun ellipse
  QGraphicsEllipseItem *sun = scene.addEllipse(0, 0, 50, 50);
  sun->setBrush(QBrush(QColor(255, 215, 0)));
  sun->setPos(-50, 75);

  // create the horizon line
  QGraphicsLineItem *horizon = scene.addLine(0, 200, 400, 200);
  horizon->setPen(QPen(QColor(220, 220, 220), 2));

  // create the time line and item animation
  QTimeLine *timeLine = new QTimeLine(10000);
  timeLine->setFrameRange(0, 100);
  QGraphicsItemAnimation *animation = new QGraphicsItemAnimation;
  animation->setItem(sun);
  animation->setTimeLine(timeLine);

  // set the animation key frames
  animation->setPosAt(0, QPointF(-50, 75));
  animation->setPosAt(0.5, QPointF(350, 75));
  animation->setPosAt(1, QPointF(-50, 75));

  // start the time line
  timeLine->start();

  // show the graphics view
  view.show();

  return app.exec();
}
