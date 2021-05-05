#ifndef GRAPHICS_SCENE_H
#define GRAPHICS_SCENE_H
//source_url = https://stackoverflow.com/questions/60770035/adding-multiple-qgraphicsscene-on-qgraphicsview
#include <QGraphicsScene>
class graphics_scene: public QGraphicsScene {
    using super = QGraphicsScene;
public:
    using super::super;
    void set_background_scene (QGraphicsScene *background_scene)
    {
        m_background_scene = background_scene;
    }
protected:
    virtual void drawBackground (QPainter *painter, const QRectF &rect) override
    {
        if (m_background_scene) {
            m_background_scene->render(painter, rect, rect);
        }
    }
private:
    QGraphicsScene *m_background_scene = nullptr;
};

#endif // GRAPHICS_SCENE_H
