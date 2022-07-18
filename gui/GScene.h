/**
 * @basename SpaceInvaders
 *
 * @authors CodeHashiras
 *
 * @class GScene
 *
 * @brief This class is an extension of QGraphicsScene with extra functionalities to handle game scenarios.
 *
 * @copyright This product includes software developed by CodeHashiras organization. See the COPYRIGHT file at the top-level directory of this distribution for details of code
 * ownership. This program is free software: you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software
 * Foundation, either version 3 of the License, or (at your option) any later version. This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY;
 * without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details. You should have received a
 * copy of the GNU General Public License along with this program. If not, see https://www.gnu.org/licenses/.
 **/

#ifndef GSCENE_H
#define GSCENE_H

#include <QObject>
#include <QGraphicsScene>
#include <QMap>
#include "gui/GSprite.h"

class GScene : public QGraphicsScene
{

    Q_OBJECT

public:

    /**
     * @brief GScene
     */
    GScene();

    bool connectOnSetSceneRequested(std::function<void(std::shared_ptr<GScene>)> func, QObject* qObject);

    void addSpriteToSceneGUI(GSpritePtr gSpritePtr);

    //addTextToSceneGUI(GTextPtr gText) override;

    //addButtonToSceneGUI(GButtonPtr gButton) override;

signals:

    /**
     * @brief signalSetSceneRequested
     * @param qGraphicsScene
     */
    void signalSetSceneRequested(std::shared_ptr<GScene> GScenePtr);

protected:

    /**
     * @brief setIdToSpriteImagePath
     * @param Id
     * @param imagePath
     */
    void setIdToSpriteImagePath(QString Id, QString imagePath);

    /**
     * @brief getPathToSprite
     * @param Id
     * @return
     */
    QString getPathToSprite(QString Id);

private:

    //
    QMap<QString, QString> _pathToSpriteID;
};

typedef std::shared_ptr<GScene> GScenePtr;

#endif // GSCENE_H
