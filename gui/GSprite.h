/**
 * @basename SpaceInvaders
 *
 * @authors CodeHashiras
 *
 * @class GSprite
 *
 * @brief This class is an image handler to show game sprites on screen, wich are graphic representations of game elements.
 *
 * @copyright This product includes software developed by CodeHashiras organization. See the COPYRIGHT file at the top-level directory of this distribution for details of code
 * ownership. This program is free software: you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software
 * Foundation, either version 3 of the License, or (at your option) any later version. This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY;
 * without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details. You should have received a
 * copy of the GNU General Public License along with this program. If not, see https://www.gnu.org/licenses/.
 **/

#ifndef GSPRITE_H
#define GSPRITE_H

#include<QObject>
#include<QGraphicsItem>
#include<QPixmap>
#include<QPainter>
#include<QMap>
#include<QTimer>

class GSprite : public QObject, public QGraphicsItem
{

    Q_OBJECT
    Q_INTERFACES()

public:

    GSprite(int width, int height, QString spritePath);

    virtual ~GSprite();

    QRectF boundingRect() const override;

    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;

    /**
     * @brief addAnimationId creates an animation name for a specific pixmap row (e.g. addAnimationId("player running", 1))
     * @param animationId is the string to be set as nickname for the pixmap row
     * @param pixmapRow is the row number you want to set a nickname of
     */
    void addAnimationId(QString animationId, int pixmapRow);

    /**
     * @brief setAnimation sets an animation based on a animation id (e.g. setAnimation("player running"))
     * @param animationId is the string which represents a pixmap row
     */
    void setAnimation(QString animationId);

    /**
     * @brief setFrame sets a specific animation frame
     * @param frameNumber is the animation frame number you want to set
     */
    void setFrame(int frameNumber);

    /**
     * @brief setFps sets animation frames per second
     * @param fps are the frames per second
     */
    void setFps(int fps);

    /**
     * @brief pauseAnimation pauses animation
     */
    void pauseAnimation();

    /**
     * @brief resumeAnimation resumes animation
     */
    void resumeAnimation();

protected slots:

    /**
     * @brief updateFrameSlot updates current animation frame based on fps value
     */
    void updateFrameSlot();

private:

    const int   PIXMAP_QRECTF_X_AXIS_ORIGIN = 0;                        // Value to be taken as QRect x axis begining
    const int   PIXMAP_QRECTF_Y_AXIS_ORIGIN = 0;                        // Value to be taken as QRect y axis begining
    const int   DEFAULT_FPS_VALUE = 15;
    const int   DEFAULT_CURRENT_ANIMATION = 0;
    const int   DEFAULT_CURRENT_FRAME = 0;
    const float DEFAULT_CURRENT_TIME_SCALED_FRAME = 0.0f;
    const float ONE_SECOND_IN_MS = 1000.0f;
    const int   BASE_FPS_TIME_IN_MS = 10;                               // Value used to set refresh timer rate (i.e. refresh timer routine is triggered every 10 ms)
    const int   MIN_FPS_VALUE = 0;                                      // Min fps value shouldn't be a negative number by convention
    const int   MAX_FPS_VALUE = ONE_SECOND_IN_MS / BASE_FPS_TIME_IN_MS; // Max fps value based on refresh timer rate (i.e 100 fps in our case)


    // Frames per second
    int _fps;

    // Sprite width
    int _width;

    // Sprite height
    int _height;

    // Computed value for max number of frames according to sprite and pixmap width
    int _spriteMaxFrames;

    // Computed value for max number of animations according to sprite and pixmap height
    int _spriteMaxAnimations;

    // Current sprite animation shown on screen
    int _currentAnimation;

    // Current sprite frame shown on screen
    int _currentFrame;

    // Represents the animation state of paused
    bool _isAnimationPaused;

    // Current sprite frame value of a determined time. Used to adapt frame transition based on fps value
    float _currentTimeScaledFrame;

    // Sprite Qpixmap raw pointer
    QPixmap *_pPixmap;

    // QMap to relate animation identifiers with pixmap row numbers
    QMap<QString, int> _animationIdsMap;

    // Number of created GSprite instances during runtime. Used to free memory
    static int _instanceCounter;

    // Refresh timer to update sprite frames on screen
    static QTimer* _pBaseFpsTimer;
};

typedef std::shared_ptr<GSprite> GSpritePtr;

#endif // GSPRITE_H
