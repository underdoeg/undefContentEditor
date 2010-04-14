#ifndef DATASTRUCTS_H
#define DATASTRUCTS_H

#include <QVariant>
#include <xmlrpc/client.h>

//this class can be extended to provide functionality of custom converting data
class dataStructHelper{
public:
    virtual xmlrpc::Variant getMediaContent(QVariant d){return xmlrpc::Variant(d.toString());};
};

struct mediaData{
    int id;
    QString type;
    QString name;
    QVariant content;
};

static mediaData toMediaData(QVariant qv){
    mediaData d;
    QMap<QString, QVariant> dat = qv.toMap()["Media"].toMap();
    d.id = dat["id"].toInt();
    d.type = dat["type"].toString();
    d.name = dat["name"].toString();
    d.content = dat["content"];
    return d;
}

static QMap<QString, xmlrpc::Variant> toMediaVariant(mediaData md, dataStructHelper* dsh = 0){
    QMap<QString, xmlrpc::Variant> dat;
    QMap<QString, xmlrpc::Variant> ff;
    ff["id"] = md.id;
    ff["name"] =md.name;
    ff["type"] = md.type;
    if(dsh != 0)
        ff["content"] = dsh->getMediaContent(md.content);
    dat["Media"] = ff;

    return dat;
};

struct pageData{
    pageData(){
        id = -1;
        title = "new Page";
    }
    QList<int> fieldIDs;
    int parent_id;
    int id;
    QString title;
};

static pageData toPageData(QVariant qv){
    pageData d;
    /*if(qv.toInt() == 0){
       qDebug("There was an error converting server field data into struct field data");
       return d;
    }*/

    QMap<QString, QVariant> dat = qv.toMap()["Page"].toMap();
    d.id = dat["id"].toInt();
    d.title = dat["title"].toString();
    d.parent_id = dat["parent_id"].toInt();

    QVariantList fields = qv.toMap()["Field"].toList();
    for(int i=0;i<fields.size();i++){
        d.fieldIDs.push_back(fields[i].toMap()["id"].toInt());
    }
    return d;
};

static QMap<QString, xmlrpc::Variant> toPageVariant(pageData fd){
    QMap<QString, xmlrpc::Variant> dat;

    QList<xmlrpc::Variant> fl;
    for(int i=0;i<fd.fieldIDs.size();i++){
        fl.push_back(fd.fieldIDs[i]);
    }
    dat["Field"] = fl;

    QMap<QString, xmlrpc::Variant> ff;
    ff["id"] = fd.id;
    ff["title"] =fd.title;
    ff["parent_id"] = fd.parent_id;
    dat["Page"] = ff;
    return dat;
};

struct fieldData{
    fieldData(){
        id = -1;
        x = 0;
        y = 0;
        w = 100;
        h = 100;
        background = QColor(220,220,220);
        content = "";
    }

    int id;
    int x;
    int y;
    int w;
    int h;
    int zindex;
    QColor background;
    QString content;
    mediaData media;
    int media_x;
    int media_y;
    int media_w;
    int media_h;
};

static fieldData toFieldData(QVariant qv){
    fieldData d;
    /*if(qv.toInt() == 0){
       qDebug("There was an error converting server field data into struct field data");
       return d;
    }*/
    QMap<QString, QVariant> dat = qv.toMap()["Field"].toMap();
    d.id = dat["id"].toInt();
    d.x = dat["x"].toInt();
    d.y = dat["y"].toInt();
    d.w = dat["w"].toInt();
    d.h = dat["h"].toInt();
    d.zindex = dat["zindex"].toInt();
    d.content = dat["content"].toString();
    d.background = QColor(dat["background"].toString());
    d.media_x = dat["media_x"].toInt();
    d.media_y = dat["media_y"].toInt();
    d.media_w = dat["media_w"].toInt();
    d.media_h = dat["media_h"].toInt();
    d.media = toMediaData(qv);
    return d;
};

static QMap<QString, xmlrpc::Variant> toFieldVariant(fieldData fd, dataStructHelper* dsh = 0){
    QMap<QString, xmlrpc::Variant> ret;
    QMap<QString, xmlrpc::Variant> dat;
    dat["id"] = fd.id;
    dat["x"] = fd.x;
    dat["y"] = fd.y;
    dat["w"] = fd.w;
    dat["h"] = fd.h;
    dat["zindex"] = fd.zindex;
    dat["background"] = fd.background.name();
    dat["content"] =fd.content;
    ret["Media"] = toMediaVariant(fd.media, dsh)["Media"];

    dat["media_x"] = fd.media_x;
    dat["media_y"] = fd.media_y;
    dat["media_w"] = fd.media_w;
    dat["media_h"] = fd.media_h;
    ret["Field"] = dat;
    return ret;
};



#endif // DATASTRUCTS_H
