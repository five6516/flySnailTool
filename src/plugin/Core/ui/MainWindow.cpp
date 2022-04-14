#include "MainWindow.h"
#include "ui_MainWindow.h"
#include "utils/UiHelper.h"
#include <QDialog>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    initForm(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::initForm(QWidget *widget)
{
    setWindowTitle("flysnailGui");

    loadPlugin();
}

void MainWindow::loadPlugin()
{
    //bool g_PluginTorL = global->getUiSetting()->getValue("PluginTorL",true).toBool();

    //寻找插件
    m_pCPluginManage->findPlugin();

    //加载插件
    m_pCPluginManage->loadPlugin();

    //加入控件界面
    int i=0;
    for(auto& plugin : m_pCPluginManage->m_mapPlugin)
    {
        if(!plugin.second->getEnable())
            continue;

        QWidget* pWidget = plugin.second->pluginWidget();

        if(plugin.second->pluginType() == Plugin_Type::pop)
        {
            pWidget->setAttribute(Qt::WA_DeleteOnClose);
            pWidget->setWindowModality(Qt::ApplicationModal);
            if(QDialog::Accepted == ((QDialog*)pWidget)->exec())
                continue;
            else
                exit(0);
        }

        ui->stackedWidget->addWidget(pWidget);//加入QStackedWidget
        plugin.second->setIndex(i++);

//        if(g_PluginTorL == PluginTOP)
//        {
//            m_pQtMaterialTabs->addTab(plugin.second->pluginName());
//        }
//        else
//        {
//            QList<QTreeWidgetItem*> listTree = m_pQTreeWidget->findItems(QString(plugin.second->pluginContent()),Qt::MatchExactly);

//            if(listTree.size() == 0)//是否存在相同根节点名
//            {
//                QTreeWidgetItem *group=new QTreeWidgetItem(m_pQTreeWidget);
//                group->setText(0,plugin.second->pluginContent());
//                QTreeWidgetItem *item=new QTreeWidgetItem(group);
//                item->setText(0,plugin.second->pluginName());
//                m_pQTreeWidget->addTopLevelItem(group);
//            }
//            else
//            {
//                for(auto root : listTree)
//                {
//                    //ShowLogFunc(root->text(0));
//                    if(root->text(0) == QString(plugin.second->pluginContent()))//添加到现有根节点
//                    {
//                        QTreeWidgetItem *item=new QTreeWidgetItem(root);
//                        item->setText(0,plugin.second->pluginName());
//                        break;
//                    }
//                }
//            }
//        }
    }

    //m_pQTreeWidget->expandAll();//展开
}
