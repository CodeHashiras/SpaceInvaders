#include "gui/GSprite.h"

int GSprite::_instanceCounter = 0;
QTimer *GSprite::_pBaseFpsTimer = new QTimer();

GSprite::GSprite(int width, int height, QString spritePath)
    : _fps(DEFAULT_FPS_VALUE)
    , _width(width)
    , _height(height)
    , _currentAnimation(DEFAULT_CURRENT_ANIMATION)
    , _currentFrame(DEFAULT_CURRENT_FRAME)
    , _currentTimeScaledFrame(DEFAULT_CURRENT_TIME_SCALED_FRAME)
    , _animationIdsMap()
{
    // Increment global sprite instances counter
    GSprite::_instanceCounter++;
    // Create pixmap which represents sprite image
    _pixmap = new QPixmap(spritePath);
    // Compute maximun rows value dividing sprite height by pixmap height
    _spriteMaxFrames = _pixmap->width()/_width;
    // Compute maximun columns value dividing sprite width by pixmap width
    _spriteMaxAnimations = _pixmap->height()/_height;
    // If base fps timer has not being actiated yet, start it
    if (!GSprite::_pBaseFpsTimer->isActive())
    {
        GSprite::_pBaseFpsTimer->start(BASE_FPS_TIME_IN_MS);
    }
    // Connect timeout signal to update frame slot method
    connect(GSprite::_pBaseFpsTimer, &QTimer::timeout, this, &GSprite::updateFrameSlot);
}

GSprite::~GSprite()
{
    // Disconnect timeout signal to update frame slot method
    disconnect(GSprite::_pBaseFpsTimer, &QTimer::timeout, this, &GSprite::updateFrameSlot);
    // When the last sprite instance is destroyed, free timer pointer memory
    if (GSprite::_instanceCounter == 1)
    {
        // Stop timer before delete it
        GSprite::_pBaseFpsTimer->stop();
        delete GSprite::_pBaseFpsTimer;
    }
    // Decrement global sprite instance counter
    GSprite::_instanceCounter--;
}

void GSprite::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    // AS: TODO
    int currentFramePixmapPosition = _currentFrame * _width;
    // AS: TODO
    int currentAnimationPixmapPosition = _currentAnimation * _height;
    // AS: TODO
    painter->drawPixmap(PIXMAP_QRECTF_X_AXIS_ORIGIN,
                        PIXMAP_QRECTF_Y_AXIS_ORIGIN,
                        *_pixmap,
                        currentFramePixmapPosition,
                        currentAnimationPixmapPosition,
                        _width,
                        _height);
}

QRectF GSprite::boundingRect() const
{
    return QRectF(PIXMAP_QRECTF_X_AXIS_ORIGIN, PIXMAP_QRECTF_Y_AXIS_ORIGIN, _width, _height);
}

void GSprite::updateFrameSlot()
{
    // AS: TODO
    _currentFrame = static_cast<int>(_currentTimeScaledFrame) % _spriteMaxFrames;
    // AS: TODO
    _currentTimeScaledFrame += (_fps * BASE_FPS_TIME_IN_MS) / ONE_SECOND_IN_MS;
    // Update pixmap QRectF to show the next sprite frame
    update();
}

void GSprite::addAnimationId(QString animationId, int pixmapRow)
{
    // AS: TODO
    if (pixmapRow < _spriteMaxAnimations)
    {
        _animationIdsMap[animationId] = pixmapRow;
    }
}

void GSprite::setAnimation(QString animationId)
{
    _currentAnimation = _animationIdsMap[animationId];
}

void GSprite::setFps(int fps)
{
    // AS: TODO
    _fps = (fps <= MAX_FPS_VALUE) ? fps : MAX_FPS_VALUE;
}
