#include "gui/Sprite.h"

int Sprite::_instanceCounter = 0;
QTimer *Sprite::_pBaseFpsTimer = new QTimer();

Sprite::Sprite(int width, int height, QString spritePath)
    : _fps(DEFAULT_FPS_VALUE)
    , _width(width)
    , _height(height)
    , _currentAnimation(DEFAULT_CURRENT_ANIMATION)
    , _currentFrame(DEFAULT_CURRENT_FRAME)
    , _currentTimeScaledFrame(DEFAULT_CURRENT_TIME_SCALED_FRAME)
    , _animationIdsMap()
{
    // Increment global sprite instances counter
    Sprite::_instanceCounter++;
    // Create pixmap which represents sprite image
    _pixmap = new QPixmap(spritePath);
    // Compute maximun rows value dividing sprite height by pixmap height
    _spriteMaxFrames = _pixmap->width()/_width;
    // Compute maximun columns value dividing sprite width by pixmap width
    _spriteMaxAnimations = _pixmap->height()/_height;
    // Start x axis of pixmap RectF from the center
    _spriteXAxisCenter = _width / 2;
    // Start y axis of pixmap RectF from the center
    _spriteYAxisCenter = _height / 2;
    // If base fps timer has not being actiated yet, start it
    if (!Sprite::_pBaseFpsTimer->isActive())
    {
        Sprite::_pBaseFpsTimer->start(BASE_FPS_TIME_IN_MS);
    }
    // Connect timeout signal to update frame slot method
    connect(Sprite::_pBaseFpsTimer, &QTimer::timeout, this, &Sprite::updateFrameSlot);
}

Sprite::~Sprite()
{
    // Disconnect timeout signal to update frame slot method
    disconnect(Sprite::_pBaseFpsTimer, &QTimer::timeout, this, &Sprite::updateFrameSlot);
    // When the last sprite instance is destroyed, free timer pointer memory
    if (Sprite::_instanceCounter == 1)
    {
        // Stop timer before delete it
        Sprite::_pBaseFpsTimer->stop();
        delete Sprite::_pBaseFpsTimer;
    }
    // Decrement global sprite instance counter
    Sprite::_instanceCounter--;
}

void Sprite::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    // AS: TODO
    int currentFramePixmapPosition = _currentFrame * _width;
    // AS: TODO
    int currentAnimationPixmapPosition = _currentAnimation * _height;
    // AS: TODO
    painter->drawPixmap(0,
                        0,
                        *_pixmap,
                        currentFramePixmapPosition,
                        currentAnimationPixmapPosition,
                        _width,
                        _height);
}

QRectF Sprite::boundingRect() const
{
    return QRectF(0, 0, _width, _height);
}

void Sprite::updateFrameSlot()
{
    // AS: TODO
    _currentFrame = static_cast<int>(_currentTimeScaledFrame) % _spriteMaxFrames;
    // AS: TODO
    _currentTimeScaledFrame += (_fps * BASE_FPS_TIME_IN_MS) / ONE_SECOND_IN_MS;
    // Update pixmap QRectF to show the next sprite frame
    update();
}

void Sprite::addAnimationId(QString animationId, int pixmapRow)
{
    // AS: TODO
    if (pixmapRow < _spriteMaxAnimations)
    {
        _animationIdsMap[animationId] = pixmapRow;
    }
}

void Sprite::setAnimation(QString animationId)
{
    _currentAnimation = _animationIdsMap[animationId];
}

void Sprite::setFps(int fps)
{
    // AS: TODO
    _fps = (fps <= MAX_FPS_VALUE) ? fps : MAX_FPS_VALUE;
}
