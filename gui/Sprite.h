/**
 * @basename SpaceInvaders
 *
 * @authors CodeHashiras
 *
 * @class Sprite
 *
 * @brief This class is an image handler to show game sprites on screen, wich are graphic representations of game elements.
 *
 * @copyright This product includes software developed by CodeHashiras organization. See the COPYRIGHT file at the top-level directory of this distribution for details of code
 * ownership. This program is free software: you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software
 * Foundation, either version 3 of the License, or (at your option) any later version. This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY;
 * without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details. You should have received a
 * copy of the GNU General Public License along with this program. If not, see https://www.gnu.org/licenses/.
 **/

#ifndef SPRITE_H
#define SPRITE_H

#include<QObject>
#include<QGraphicsItem>
#include<QPixmap>
#include<QPainter>
#include<QMap>
#include<QTimer>

class Sprite : public QObject, public QGraphicsItem
{
    Q_OBJECT

public:

    Sprite(int width, int height, QString spritePath);

    virtual ~Sprite();

    /**
     * @brief AS: TODO
     * @param
     *
     * @return
     **/
    QRectF boundingRect() const override;

    /**
     * @brief AS: TODO
     * @param
     *
     * @return
     **/
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;

    /**
     * @brief AS: TODO
     * @param
     *
     * @return
     **/
    void addAnimationId(QString animationId, int pixmapRow);

    /**
     * @brief AS: TODO
     * @param
     *
     * @return
     **/
    void setAnimation(QString animationId);

    /**
     * @brief AS: TODO
     * @param
     *
     * @return
     **/
    void setFps(int fps);

protected slots:

    /**
     * @brief AS: TODO
     * @param
     *
     * @return
     **/
    void updateFrameSlot();

private:

    const int   PIXMAP_QRECTF_X_AXIS_ORIGIN = 0;                        //
    const int   PIXMAP_QRECTF_Y_AXIS_ORIGIN = 0;                        //
    const int   DEFAULT_FPS_VALUE = 15;                                 //
    const int   DEFAULT_CURRENT_ANIMATION = 0;                          //
    const int   DEFAULT_CURRENT_FRAME = 0;                              //
    const float DEFAULT_CURRENT_TIME_SCALED_FRAME = 0.0f;               //
    const float ONE_SECOND_IN_MS = 1000.0f;                             //
    const int   BASE_FPS_TIME_IN_MS = 10;                               //
    const int   MAX_FPS_VALUE = ONE_SECOND_IN_MS / BASE_FPS_TIME_IN_MS; //

    // AS: TODO
    int _fps;

    // AS: TODO
    int _width;

    // AS: TODO
    int _height;

    // AS: TODO
    int _spriteMaxFrames;

    // AS: TODO
    int _spriteMaxAnimations;

    // AS: TODO
    int _currentAnimation;

    // AS: TODO
    int _currentFrame;

    // AS: TODO
    float _currentTimeScaledFrame;

    // AS: TODO
    QPixmap *_pixmap;

    // AS: TODO
    QMap<QString, int> _animationIdsMap;

    // AS: TODO
    static int _instanceCounter;

    // AS: TODO
    static QTimer* _pBaseFpsTimer;
};

#endif // SPRITE_H
