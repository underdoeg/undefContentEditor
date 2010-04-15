#include "page.h"
#include "pagehandler.h"

page::page(QWidget *parent) :
        QWidget(parent)
{
    QHBoxLayout* layout =  new QHBoxLayout();
    layout->setMargin(0);

    setLayout(layout);
    scrollArea = new QScrollArea();
    scrollArea->setStyleSheet("");
    layout->addWidget(scrollArea);

    fieldRoot = new QWidget();
    fieldRoot->setStyleSheet("background-color:transparent");
    scrollArea->setWidget(fieldRoot);

    fieldOverlay = new QWidget(fieldRoot);
    fieldOverlay->setStyleSheet("background-color: rgba(60, 60, 0, 40);");//border: 1px solid #FF6030");
    fieldOverlay->setEnabled(false);
    fieldOverlay->setAttribute(Qt::WA_TransparentForMouseEvents); //ignore mouse
    fieldOverlay->setFocusPolicy( Qt::NoFocus );//ignore keyboard
    fieldOverlayHide();
    treeWidgetItem = new QTreeWidgetItem();
    treeWidgetItem->setText(0, "loading...");
    dataChanged = false;
}

void page::resetMinSize(){
    int mx=0;
    int my=0;
    for(int i=0;i<fields.size();i++){
        if(fields[i]->geometry().right()>mx)
            mx = fields[i]->geometry().right();
        if(fields[i]->geometry().bottom()>my)
            my = fields[i]->geometry().bottom();
    }
    fieldRoot->setGeometry(0,0,mx+GRID_SIZE, my+GRID_SIZE);
    fieldRoot->setMinimumSize(mx+GRID_SIZE, my+GRID_SIZE);
}

void page::fieldMoved(field *f){
    resetMinSize();
}

void page::fieldResized(field *f){
    resetMinSize();
}

void page::load(int id){
    ServerAPI::getPageData(this, id);
    data.id = id;
}

void page::onPageData(pageData pd){
    data = pd;
    dataChanged = true;
    //update the tree widget item
    treeWidgetItem->setText(0,data.title);
    if(data.parent_id>0){
        page* p = pageHandler::getPageByID(data.parent_id);
        if(p!=0){
            p->treeWidgetItem->addChild(treeWidgetItem);
        }
    }else{
        pageHandler::treeWidget->addTopLevelItem(treeWidgetItem);
    }
}

void page::parseData(){
    if(!dataChanged)
        return;
    //create the fields
    for(int i=0;i<data.fieldIDs.size();i++){
        createField(data.fieldIDs[i]);
    }
    dataChanged = false;
}

void page::createField(int id){
    field* f = new field(fieldRoot);
    f->parent = this;
    f->stackUnder(fieldOverlay);
    if(id>0)
        f->load(id);
    else{
        fieldData d;
        f->onFieldData(d);
    }
    addField(f);
}

void page::save(){
    ServerAPI::savePageData(this, data);
}

void page::onPageSave(int id){
    data.id = id;
    for(int i=0;i<fields.size();i++){
        fields[i]->save();
    }
}

void page::addField(field* f){
    f->addFieldListener(this);
    fields.push_back(f);
    resetMinSize();
}

int page::getID(){
    return data.id;
}

void page::activeFieldSelectBackground(){
    if(selectedFields.size()==0)
        return;
    selectedFields[0]->selectBackgroundColor();
}

void page::addImage(bool showLoad){
    if(selectedFields.size()==0)
        return;
    selectedFields[0]->addImage(showLoad);
}

void page::toggleTextEdit(){
    if(selectedFields.size()==0)
        return;
    selectedFields[0]->toggleTextEdit();;
}

void page::selectFields(field* f){
    unselectFields();
    selectedFields.push_back(f);
    f->highlite();
}

void page::unselectFields(){
    for(int i=0;i<selectedFields.size();i++){
        selectedFields[i]->unhighlite();
    }
    selectedFields.clear();
}

void page::mouseReleaseEvent ( QMouseEvent * event ){
    unselectFields();
}

QRect page::fieldOverlayGetPosition(){
    return fieldOverlay->geometry();
}


void page::fieldOverlayShow(){
    fieldOverlay->setVisible(true);
}

void page::fieldOverlayHide(){
    fieldOverlay->setVisible(false);
}

void page::fieldOverlayPosition(int x, int y, int w, int h){
    fieldOverlay->setGeometry(x, y, w, h);
}

void page::fieldOverlayPosition(QRect r){
    fieldOverlay->setGeometry(r);
}
