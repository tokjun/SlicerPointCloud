/*=auto=========================================================================

Portions (c) Copyright 2005 Brigham and Women's Hospital (BWH) All Rights Reserved.

See COPYRIGHT.txt
or http://www.slicer.org/copyright/copyright.txt for details.

Program:   3D Slicer
Module:    $RCSfile: vtkMRMLPointCloudDisplayNode.cxx,v $
Date:      $Date: 2006/03/03 22:26:39 $
Version:   $Revision: 1.3 $

=========================================================================auto=*/
// MRML includes
#include "vtkMRMLPointCloudDisplayNode.h"

// VTK includes
#include <vtkAlgorithmOutput.h>
#include <vtkAssignAttribute.h>
#include <vtkCommand.h>
#include <vtkObjectFactory.h>
#include <vtkPassThrough.h>
#include <vtkPolyData.h>
#include <vtkVersion.h>

//----------------------------------------------------------------------------
vtkMRMLNodeNewMacro(vtkMRMLPointCloudDisplayNode);

//-----------------------------------------------------------------------------
vtkMRMLPointCloudDisplayNode::vtkMRMLPointCloudDisplayNode()
{
  this->PassThrough = vtkPassThrough::New();
  this->AssignAttribute = vtkAssignAttribute::New();

  // the default behavior for models is to use the scalar range of the data
  // to reset the display scalar range, so use the Data flag
  this->SetScalarRangeFlag(vtkMRMLDisplayNode::UseDataScalarRange);

  // Be careful, virtualization doesn't work in constructors
  this->UpdatePolyDataPipeline();
}

//-----------------------------------------------------------------------------
vtkMRMLPointCloudDisplayNode::~vtkMRMLPointCloudDisplayNode()
{
  this->PassThrough->Delete();
  this->AssignAttribute->Delete();
}

//---------------------------------------------------------------------------
void vtkMRMLPointCloudDisplayNode::ProcessMRMLEvents(vtkObject *caller,
                                                unsigned long event,
                                                void *callData )
{
  this->Superclass::ProcessMRMLEvents(caller, event, callData);

  if (event == vtkCommand::ModifiedEvent)
    {
    this->UpdatePolyDataPipeline();
    }
}

//---------------------------------------------------------------------------
void vtkMRMLPointCloudDisplayNode
::SetInputPolyDataConnection(vtkAlgorithmOutput* polyDataConnection)
{
  if (this->GetInputPolyDataConnection() == polyDataConnection)
    {
    return;
    }
  this->SetInputToPolyDataPipeline(polyDataConnection);
  this->Modified();
}

//---------------------------------------------------------------------------
void vtkMRMLPointCloudDisplayNode
::SetInputToPolyDataPipeline(vtkAlgorithmOutput* polyDataConnection)
{
  this->PassThrough->SetInputConnection(polyDataConnection);
  this->AssignAttribute->SetInputConnection(polyDataConnection);
}

//---------------------------------------------------------------------------
vtkPolyData* vtkMRMLPointCloudDisplayNode::GetInputPolyData()
{
  return vtkPolyData::SafeDownCast(this->AssignAttribute->GetInput());
}

//---------------------------------------------------------------------------
vtkAlgorithmOutput* vtkMRMLPointCloudDisplayNode::GetInputPolyDataConnection()
{
  return this->AssignAttribute->GetNumberOfInputConnections(0) ?
    this->AssignAttribute->GetInputConnection(0,0) : 0;
}

//---------------------------------------------------------------------------
vtkPolyData* vtkMRMLPointCloudDisplayNode::GetOutputPolyData()
{
  if (!this->GetOutputPolyDataConnection())
    {
    return 0;
    }
  if (!this->GetInputPolyData())
    {
    return 0;
    }
  return vtkPolyData::SafeDownCast(
    this->GetOutputPolyDataConnection()->GetProducer()->GetOutputDataObject(
      this->GetOutputPolyDataConnection()->GetIndex()));
}

//---------------------------------------------------------------------------
vtkAlgorithmOutput* vtkMRMLPointCloudDisplayNode::GetOutputPolyDataConnection()
{
  if (this->GetActiveScalarName())
    {
    return this->AssignAttribute->GetOutputPort();
    }
  else
    {
    return this->PassThrough->GetOutputPort();
    }
}

//---------------------------------------------------------------------------
void vtkMRMLPointCloudDisplayNode::SetActiveScalarName(const char *scalarName)
{
  if (scalarName && this->ActiveScalarName && !strcmp(scalarName, this->ActiveScalarName))
    {
    return;
    }
  if (scalarName == 0 && this->ActiveScalarName == 0)
    {
    return;
    }
  int wasModifying = this->StartModify();
  this->Superclass::SetActiveScalarName(scalarName);
  this->UpdatePolyDataPipeline();
  this->EndModify(wasModifying);
}

//---------------------------------------------------------------------------
void vtkMRMLPointCloudDisplayNode::SetActiveAttributeLocation(int location)
{
  if (location == this->ActiveAttributeLocation)
    {
    return;
    }
  int wasModifying = this->StartModify();
  this->Superclass::SetActiveAttributeLocation(location);
  this->UpdatePolyDataPipeline();
  this->EndModify(wasModifying);
}

//---------------------------------------------------------------------------
void vtkMRMLPointCloudDisplayNode::UpdatePolyDataPipeline()
{
  this->AssignAttribute->Assign(
    this->GetActiveScalarName(),
    this->GetActiveScalarName() ? vtkDataSetAttributes::SCALARS : -1,
    this->GetActiveAttributeLocation());
  if (this->GetOutputPolyData())
    {
    this->GetOutputPolyDataConnection()->GetProducer()->Update();
    if (this->GetAutoScalarRange())
      {
      vtkDebugMacro("UpdatePolyDataPipeline: Auto flag is on, resetting scalar range!");
      this->SetScalarRange(this->GetOutputPolyData()->GetScalarRange());
      }
    }
}
