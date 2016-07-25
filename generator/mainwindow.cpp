#include "mainwindow.h"
#include "ui_scene_gen.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->Particularity->setEnabled(false);
    ui->Transformation->setEnabled(false);
    m_button = new QVector<QRadioButton *>;
    m_button->append(ui->Cone);
    m_button->push_back(ui->Cylindre);
    m_button->push_back(ui->Sphere);
    m_button->push_back(ui->Spot);
    m_button->push_back(ui->Eye);
    m_button->push_back(ui->Plan);
    connect(ui->Eye, SIGNAL(clicked()), this, SLOT(setEyeWidget()));
    connect(ui->Plan, SIGNAL(clicked()), this, SLOT(setPlanWidget()));
    connect(ui->Sphere, SIGNAL(clicked()), this, SLOT(setItemWidget()));
    connect(ui->Cone, SIGNAL(clicked()), this, SLOT(setItemWidget()));
    connect(ui->Cylindre, SIGNAL(clicked()), this, SLOT(setItemWidget()));
    connect(ui->Spot, SIGNAL(clicked()), this, SLOT(setSpotWidget()));
    connect(ui->color_button, SIGNAL(clicked()), this, SLOT(set_color_button()));
    connect(ui->add_button, SIGNAL(clicked()), this, SLOT(add_item_to_file()));
    connect(ui->generate_button, SIGNAL(clicked()), this, SLOT(generate_file()));
    _eye = false;
}

MainWindow::~MainWindow()
{
    delete ui;
    delete m_button;
}

/*
** SLOTS
*/

void                    MainWindow::setEyeWidget()
{
    ui->Transformation->setEnabled(true);
    ui->ray->setEnabled(false);
    ui->Particularity->setEnabled(false);
    ui->label_ray->setEnabled(false);
    ui->Rotations->setEnabled(true);
    ui->color_l->setText("");
}

void                    MainWindow::setItemWidget()
{
    ui->Transformation->setEnabled(true);
    ui->Particularity->setEnabled(true);
    ui->Effect->setEnabled(true);
    ui->i->setEnabled(false);
    ui->ray->setEnabled(true);
    ui->label_ray->setEnabled(true);
    ui->label_24->setEnabled(false);
    ui->color_l->setText("#000000");
}

void                    MainWindow::setSpotWidget()
{
    ui->Transformation->setEnabled(true);
    ui->Rotations->setEnabled(false);
    ui->Particularity->setEnabled(true);
    ui->ray->setEnabled(false);
    ui->label_ray->setEnabled(false);
    ui->label_24->setEnabled(true);
    ui->Effect->setEnabled(false);
    ui->i->setEnabled(true);
    ui->color_l->setText("#000000");
}

void                    MainWindow::setPlanWidget()
{
    ui->Transformation->setEnabled(true);
    ui->Rotations->setEnabled(true);
    ui->Particularity->setEnabled(true);
    ui->ray->setEnabled(false);
    ui->label_ray->setEnabled(false);
    ui->Effect->setEnabled(true);
    ui->i->setEnabled(false);
    ui->label_24->setEnabled(false);
    ui->color_l->setText("#000000");
}

void                    MainWindow::set_color_button()
{
   QColor color =   QColorDialog::getColor(Qt::white,  this);
   ui->color_l->setText(color.name());
}

void                    MainWindow::add_item_to_file()
{
    bool        check = false;
    QTreeWidgetItem     *new_item;

    for (int i = 0; i < m_button->size() ; ++i)
        if (m_button->at(i)->isChecked()){
            if (m_button->at(i)->text() == "Eye" && _eye == true){
                QMessageBox::information(this, "Error", "Eye already set");
                return;
            }
            new_item = new QTreeWidgetItem(ui->treeWidget);
            new_item->setText(0, m_button->at(i)->text());
            if (m_button->at(i)->text() == "Eye")
                _eye = true;
            check = true;
            break;
        }
    if (check == false){
        QMessageBox::information(this, "Error", "No item to add");
        return;
    }
    get_transformation(new_item);
    get_particularity(new_item);
}

void                    MainWindow::generate_file() {

    if (_eye == false) {
        QMessageBox::information(this, "Error", "You need to set the eye position");
        return;
    }
    QString file_name = QFileDialog::getSaveFileName(this, "File register", QString(), "Scenes (*.scene *.objs *.map *.rt)");
    QFile file(file_name);
    if (!file.open(QIODevice::WriteOnly | QIODevice::Text))
        QMessageBox::information(this, "Error", "Can't open file");
    QTextStream flux(&file);
    flux.setCodec("UTF-8");
    for (QTreeWidgetItem *current = ui->treeWidget->itemAt(0, 0);  current; current = ui->treeWidget->itemBelow(current)){
            if (current->isExpanded())
                   current->setExpanded(false);
        flux << current->text(0).toUpper() << endl;
        for (int i = 0; current->child(i); ++i)
          flux << current->child(i)->text(0).toUpper() << "=" << "     " << current->child(i)->child(0)->text(0) << endl;
          flux << "//" << endl;
    }
    QMessageBox::information(this, "Generat", "your file " + file_name + " has been saved");
    this->close();
}

/*
** PRIVATE
*/

void                    MainWindow::get_transformation(QTreeWidgetItem *parent) {
    QTreeWidgetItem     *position;
    QTreeWidgetItem     *rotation;
    QTreeWidgetItem     *ray;

    if (ui->Positions->isEnabled()) {
        position = new QTreeWidgetItem(parent);
        position->setText(0, QString("Position"));
        position->addChild(new QTreeWidgetItem);
        position->child(0)->setText(0, QString::number(ui->pos_x->value()) + "       "
                                                       + QString::number(ui->pos_y->value()) + "       "
                                                       + QString::number(ui->pos_z->value()));
    }
    if (ui->Rotations->isEnabled()) {
        rotation = new QTreeWidgetItem(parent);
        rotation->setText(0, QString("Rotation"));
        rotation->addChild(new QTreeWidgetItem);
        rotation->child(0)->setText(0, QString::number(ui->rot_x->value()) + "       "
                                                      + QString::number(ui->rot_y->value()) + "       "
                                                      + QString::number(ui->rot_z->value()));
    }
    if (ui->ray->isEnabled()) {
        ray = new QTreeWidgetItem(parent);
        ray->setText(0, QString("Ray"));
        ray->addChild(new QTreeWidgetItem);
        ray->child(0)->setText(0, QString::number(ui->ray->value()));
    }
}

void                    MainWindow::get_particularity(QTreeWidgetItem *parent){
    QTreeWidgetItem     *effect;
    QTreeWidgetItem     *i;
    QTreeWidgetItem     *color;

    if (ui->Effect->isEnabled()){
        effect = new QTreeWidgetItem(parent);
        effect->setText(0, "Effect");
        effect->addChild(new QTreeWidgetItem);
        effect->child(0)->setText(0, QString::number(ui->b->value()) + "       "
                                                       + QString::number(ui->t->value()) + "       "
                                                       + QString::number(ui->r->value()));

    }
    if (ui->label_24->isEnabled()){
        i = new QTreeWidgetItem(parent);
        i->setText(0, "Intensity");
        i->addChild(new QTreeWidgetItem);
        i->child(0)->setText(0, QString::number(ui->i->value()));
    }
    if (ui->color_button->isEnabled()){
        color = new QTreeWidgetItem(parent);
        color->setText(0, "Color");
        color->addChild(new QTreeWidgetItem);
        color->child(0)->setBackgroundColor(0, QColor(ui->color_l->text()));
        color->child(0)->setText(0, ui->color_l->text().remove(0, 1));
    }
}
