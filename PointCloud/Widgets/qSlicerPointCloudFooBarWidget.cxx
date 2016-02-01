/*==============================================================================

  Program: 3D Slicer

  Copyright (c) Kitware Inc.

  See COPYRIGHT.txt
  or http://www.slicer.org/copyright/copyright.txt for details.

  Unless required by applicable law or agreed to in writing, software
  distributed under the License is distributed on an "AS IS" BASIS,
  WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
  See the License for the specific language governing permissions and
  limitations under the License.

  This file was originally developed by Jean-Christophe Fillion-Robin, Kitware Inc.
  and was partially funded by NIH grant 3P41RR013218-12S1

==============================================================================*/

// FooBar Widgets includes
#include "qSlicerPointCloudFooBarWidget.h"
#include "ui_qSlicerPointCloudFooBarWidget.h"

//-----------------------------------------------------------------------------
/// \ingroup Slicer_QtModules_PointCloud
class qSlicerPointCloudFooBarWidgetPrivate
  : public Ui_qSlicerPointCloudFooBarWidget
{
  Q_DECLARE_PUBLIC(qSlicerPointCloudFooBarWidget);
protected:
  qSlicerPointCloudFooBarWidget* const q_ptr;

public:
  qSlicerPointCloudFooBarWidgetPrivate(
    qSlicerPointCloudFooBarWidget& object);
  virtual void setupUi(qSlicerPointCloudFooBarWidget*);
};

// --------------------------------------------------------------------------
qSlicerPointCloudFooBarWidgetPrivate
::qSlicerPointCloudFooBarWidgetPrivate(
  qSlicerPointCloudFooBarWidget& object)
  : q_ptr(&object)
{
}

// --------------------------------------------------------------------------
void qSlicerPointCloudFooBarWidgetPrivate
::setupUi(qSlicerPointCloudFooBarWidget* widget)
{
  this->Ui_qSlicerPointCloudFooBarWidget::setupUi(widget);
}

//-----------------------------------------------------------------------------
// qSlicerPointCloudFooBarWidget methods

//-----------------------------------------------------------------------------
qSlicerPointCloudFooBarWidget
::qSlicerPointCloudFooBarWidget(QWidget* parentWidget)
  : Superclass( parentWidget )
  , d_ptr( new qSlicerPointCloudFooBarWidgetPrivate(*this) )
{
  Q_D(qSlicerPointCloudFooBarWidget);
  d->setupUi(this);
}

//-----------------------------------------------------------------------------
qSlicerPointCloudFooBarWidget
::~qSlicerPointCloudFooBarWidget()
{
}
