/*=auto=========================================================================

  Portions (c) Copyright 2005 Brigham and Women's Hospital (BWH) All Rights Reserved.

  See COPYRIGHT.txt
  or http://www.slicer.org/copyright/copyright.txt for details.

  Program:   3D Slicer
  Module:    $RCSfile: vtkMRMLPointCloudStorageNode.h,v $
  Date:      $Date: 2006/03/19 17:12:29 $
  Version:   $Revision: 1.3 $

=========================================================================auto=*/

#ifndef __vtkMRMLPointCloudStorageNode_h
#define __vtkMRMLPointCloudStorageNode_h

#include "vtkMRMLStorageNode.h"

/// \brief MRML node for model storage on disk.
///
/// Storage nodes has methods to read/write vtkPolyData to/from disk.
class VTK_MRML_EXPORT vtkMRMLPointCloudStorageNode : public vtkMRMLStorageNode
{
public:
  static vtkMRMLPointCloudStorageNode *New();
  vtkTypeMacro(vtkMRMLPointCloudStorageNode,vtkMRMLStorageNode);
  void PrintSelf(ostream& os, vtkIndent indent);

  virtual vtkMRMLNode* CreateNodeInstance();

  ///
  /// Get node XML tag name (like Storage, PointCloud)
  virtual const char* GetNodeTagName()  {return "PointCloudStorage";};

  /// Return a default file extension for writting
  virtual const char* GetDefaultWriteFileExtension();

  /// Return true if the reference node can be read in
  virtual bool CanReadInReferenceNode(vtkMRMLNode *refNode);

protected:
  vtkMRMLPointCloudStorageNode();
  ~vtkMRMLPointCloudStorageNode();
  vtkMRMLPointCloudStorageNode(const vtkMRMLPointCloudStorageNode&);
  void operator=(const vtkMRMLPointCloudStorageNode&);

  /// Initialize all the supported read file types
  virtual void InitializeSupportedReadFileTypes();

  /// Initialize all the supported write file types
  virtual void InitializeSupportedWriteFileTypes();

  /// Read data and set it in the referenced node
  virtual int ReadDataInternal(vtkMRMLNode *refNode);

  /// Write data from a  referenced node
  virtual int WriteDataInternal(vtkMRMLNode *refNode);

};

#endif
