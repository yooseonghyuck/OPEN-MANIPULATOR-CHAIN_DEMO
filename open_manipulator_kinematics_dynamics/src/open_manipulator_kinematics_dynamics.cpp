/*******************************************************************************
 * Copyright (c) 2016, ROBOTIS CO., LTD.
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *
 * * Redistributions of source code must retain the above copyright notice, this
 *   list of conditions and the following disclaimer.
 *
 * * Redistributions in binary form must reproduce the above copyright notice,
 *   this list of conditions and the following disclaimer in the documentation
 *   and/or other materials provided with the distribution.
 *
 * * Neither the name of ROBOTIS nor the names of its
 *   contributors may be used to endorse or promote products derived from
 *   this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
 * DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE
 * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
 * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
 * SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
 * CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,
 * OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
 * OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 *******************************************************************************/

/*
 * Link.cpp
 *
 *  Created on: Jan 11, 2016
 *      Author: sch
 */

#include <iostream>
#include "open_manipulator_kinematics_dynamics/open_manipulator_kinematics_dynamics.h"

namespace open_manipulator
{

KinematicsDynamics::KinematicsDynamics()
{
}
KinematicsDynamics::~KinematicsDynamics()
{
}

KinematicsDynamics::KinematicsDynamics(TreeSelect tree)
{
  for (int id = 0; id <= ALL_JOINT_ID; id++)
    link_data_[id] = new LinkData();

  if (tree == ARM)
  {
    link_data_[0]->name_    = "base";
    link_data_[0]->parent_  = -1;
    link_data_[0]->sibling_ = -1;
    link_data_[0]->child_   = 1;
    link_data_[0]->mass_    = 0.0;
    link_data_[0]->relative_position_ = robotis_framework::getTransitionXYZ(0.0, 0.0, 0.0);
    link_data_[0]->joint_axis_        = robotis_framework::getTransitionXYZ(0.0, 0.0, 0.0);
    link_data_[0]->center_of_mass_    = robotis_framework::getTransitionXYZ(0.0, 0.0, 0.0);
    link_data_[0]->joint_limit_max_   = 100.0;
    link_data_[0]->joint_limit_min_   = -100.0;
    link_data_[0]->inertia_           = robotis_framework::getInertiaXYZ(0.0, 0.0, 0.0, 0.0, 0.0, 0.0);

    link_data_[1]->name_    = "joint1";
    link_data_[1]->parent_  = 0;
    link_data_[1]->sibling_ = -1;
    link_data_[1]->child_   = 2;
    link_data_[1]->mass_    = 1.0;
    link_data_[1]->relative_position_ = robotis_framework::getTransitionXYZ(0.012, 0.0, 0.036);
    link_data_[1]->joint_axis_        = robotis_framework::getTransitionXYZ(0.0, 0.0, 1.0);
    link_data_[1]->center_of_mass_    = robotis_framework::getTransitionXYZ(0.0, 0.0, 0.0);
    link_data_[1]->joint_limit_max_   = 0.5 * M_PI;
    link_data_[1]->joint_limit_min_   = -0.5 * M_PI;
    link_data_[1]->inertia_           = robotis_framework::getInertiaXYZ(1.0, 0.0, 0.0, 1.0, 0.0, 1.0);

    link_data_[2]->name_    = "joint2";
    link_data_[2]->parent_  = 1;
    link_data_[2]->sibling_ = -1;
    link_data_[2]->child_   = 3;
    link_data_[2]->mass_    = 1.0;
    link_data_[2]->relative_position_ = robotis_framework::getTransitionXYZ(0.0, 0.0, 0.040);
    link_data_[2]->joint_axis_        = robotis_framework::getTransitionXYZ(0.0, 1.0, 0.0);
    link_data_[2]->center_of_mass_    = robotis_framework::getTransitionXYZ(0.0, 0.0, 0.0);
    link_data_[2]->joint_limit_max_   = 0.5 * M_PI;
    link_data_[2]->joint_limit_min_   = -0.5 * M_PI;
    link_data_[2]->inertia_           = robotis_framework::getInertiaXYZ(1.0, 0.0, 0.0, 1.0, 0.0, 1.0);

    link_data_[3]->name_    = "joint3";
    link_data_[3]->parent_  = 2;
    link_data_[3]->sibling_ = -1;
    link_data_[3]->child_   = 4;
    link_data_[3]->mass_    = 1.0;
    link_data_[3]->relative_position_ = robotis_framework::getTransitionXYZ(0.022, 0.0, 0.122);
    link_data_[3]->joint_axis_        = robotis_framework::getTransitionXYZ(0.0, -1.0, 0.0);
    link_data_[3]->center_of_mass_    = robotis_framework::getTransitionXYZ(0.0, 0.0, 0.0);
    link_data_[3]->joint_limit_max_   = 0.5 * M_PI;
    link_data_[3]->joint_limit_min_   = -0.5 * M_PI;
    link_data_[3]->inertia_           = robotis_framework::getInertiaXYZ(1.0, 0.0, 0.0, 1.0, 0.0, 1.0);

    link_data_[4]->name_    = "joint4";
    link_data_[4]->parent_  = 3;
    link_data_[4]->sibling_ = -1;
    link_data_[4]->child_   = 5;
    link_data_[4]->mass_    = 1.0;
    link_data_[4]->relative_position_ = robotis_framework::getTransitionXYZ(0.124, 0.0, 0.0);
    link_data_[4]->joint_axis_        = robotis_framework::getTransitionXYZ(0.0, 1.0, 0.0);
    link_data_[4]->center_of_mass_    = robotis_framework::getTransitionXYZ(0.0, 0.0, 0.0);
    link_data_[4]->joint_limit_max_   = 0.5 * M_PI;
    link_data_[4]->joint_limit_min_   = -0.5 * M_PI;
    link_data_[4]->inertia_           = robotis_framework::getInertiaXYZ(1.0, 0.0, 0.0, 1.0, 0.0, 1.0);

    link_data_[5]->name_    = "end";
    link_data_[5]->parent_  = 4;
    link_data_[5]->sibling_ = -1;
    link_data_[5]->child_   = -1;
    link_data_[5]->mass_    = 0.0;
    link_data_[5]->relative_position_ = robotis_framework::getTransitionXYZ(0.071, 0.0, 0.0);
    link_data_[5]->joint_axis_        = robotis_framework::getTransitionXYZ(0.0, 0.0, 0.0);
    link_data_[5]->center_of_mass_    = robotis_framework::getTransitionXYZ(0.0, 0.0, 0.0);
    link_data_[5]->joint_limit_max_   = 100.0;
    link_data_[5]->joint_limit_min_   = -100.0;
    link_data_[5]->inertia_           = robotis_framework::getInertiaXYZ(1.0, 0.0, 0.0, 1.0, 0.0, 1.0);
  }
}

std::vector<int> KinematicsDynamics::findRoute(int to)
{
  int id = link_data_[to]->parent_;

  std::vector<int> idx;

  if (id == 0)
  {
    idx.push_back(0);
    idx.push_back(to);
  }
  else
  {
    idx = findRoute(id);
    idx.push_back(to);
  }

  return idx;
}

std::vector<int> KinematicsDynamics::findRoute(int from, int to)
{
  int id = link_data_[to]->parent_;

  std::vector<int> idx;

  if (id == from)
  {
    idx.push_back(from);
    idx.push_back(to);
  }
  else if (id != 0)
  {
    idx = findRoute(from, id);
    idx.push_back(to);
  }

  return idx;
}

double KinematicsDynamics::totalMass(int joint_ID)
{
  double mass;

  if (joint_ID == -1)
    mass = 0.0;
  else
    mass = link_data_[joint_ID]->mass_ + totalMass(link_data_[joint_ID]->sibling_)
                                                   + totalMass(link_data_[joint_ID]->child_);

  return mass;
}

Eigen::MatrixXd KinematicsDynamics::calcMC(int joint_ID)
{
  Eigen::MatrixXd mc(3, 1);

  if (joint_ID == -1)
    mc = Eigen::MatrixXd::Zero(3, 1);
  else
  {
    mc = link_data_[joint_ID]->mass_ * (link_data_[joint_ID]->orientation_
        * link_data_[joint_ID]->center_of_mass_ + link_data_[joint_ID]->position_);
    mc = mc + calcMC(link_data_[joint_ID]->sibling_) + calcMC(link_data_[joint_ID]->child_);
  }

  return mc;
}

Eigen::MatrixXd KinematicsDynamics::calcCOM(Eigen::MatrixXd MC)
{
  double mass;
  Eigen::MatrixXd COM(3, 1);

  mass = totalMass(0);

  COM = MC / mass;

  return COM;
}

void KinematicsDynamics::forwardKinematics(int joint_ID)
{
  if (joint_ID == -1)
    return;

  link_data_[0]->position_ = Eigen::MatrixXd::Zero(3, 1);
  link_data_[0]->orientation_ = robotis_framework::calcRodrigues(
                                                robotis_framework::calcHatto(link_data_[0]->joint_axis_),
                                                link_data_[0]->joint_angle_
                                            );

  if (joint_ID != 0)
  {
    int parent = link_data_[joint_ID]->parent_;

    link_data_[joint_ID]->position_ = link_data_[parent]->orientation_
                                                  * link_data_[joint_ID]->relative_position_
                                                  + link_data_[parent]->position_;
    link_data_[joint_ID]->orientation_ = link_data_[parent]->orientation_
                                                    * robotis_framework::calcRodrigues(robotis_framework::calcHatto(link_data_[joint_ID]->joint_axis_),
                                                                                       link_data_[joint_ID]->joint_angle_);

    link_data_[joint_ID]->transformation_.block<3, 1>(0, 3) = link_data_[joint_ID]->position_;
    link_data_[joint_ID]->transformation_.block<3, 3>(0, 0) = link_data_[joint_ID]->orientation_;
  }

  forwardKinematics(link_data_[joint_ID]->sibling_);
  forwardKinematics(link_data_[joint_ID]->child_);
}

Eigen::MatrixXd KinematicsDynamics::calcJacobian(std::vector<int> idx)
{
  int idx_size = idx.size();
  int end = idx_size - 1;

  Eigen::MatrixXd tar_position = link_data_[idx[end]]->position_;
  Eigen::MatrixXd Jacobian = Eigen::MatrixXd::Zero(6, idx_size);

  for (int index = 0; index < idx_size; index++)
  {
    int id = idx[index];

    Eigen::MatrixXd tar_orientation = link_data_[id]->orientation_ * link_data_[id]->joint_axis_;

    Jacobian.block(0, index, 3, 1) = robotis_framework::calcCross(tar_orientation,
                                                                  tar_position - link_data_[id]->position_);
    Jacobian.block(3, index, 3, 1) = tar_orientation;
  }

  return Jacobian;
}

Eigen::MatrixXd KinematicsDynamics::calcJacobianOnlyPosition(std::vector<int> idx)
{
  int idx_size = idx.size();
  int end = idx_size - 1;

  Eigen::MatrixXd tar_position = link_data_[idx[end]]->position_;
  Eigen::MatrixXd Jacobian = Eigen::MatrixXd::Zero(3, idx_size);

  for (int index = 0; index < idx_size; index++)
  {
    int id = idx[index];

    Eigen::MatrixXd tar_orientation = link_data_[id]->orientation_ * link_data_[id]->joint_axis_;

    Jacobian.block(0, index, 3, 1) = robotis_framework::calcCross(tar_orientation,
                                                                  tar_position - link_data_[id]->position_);
  }

  return Jacobian;
}

Eigen::MatrixXd KinematicsDynamics::calcJacobianCOM(std::vector<int> idx)
{
  int idx_size = idx.size();
  int end = idx_size - 1;

  Eigen::MatrixXd target_position = link_data_[idx[end]]->position_;
  Eigen::MatrixXd jacobianCOM = Eigen::MatrixXd::Zero(6, idx_size);

  for (int index = 0; index < idx_size; index++)
  {
    int     id    = idx[index];
    double  mass  = totalMass(id);

    Eigen::MatrixXd og = calcMC(id) / mass - link_data_[id]->position_;
    Eigen::MatrixXd target_orientation = link_data_[id]->orientation_ * link_data_[id]->joint_axis_;

    jacobianCOM.block(0, index, 3, 1) = robotis_framework::calcCross(target_orientation, og);
    jacobianCOM.block(3, index, 3, 1) = target_orientation;
  }

  return jacobianCOM;
}

Eigen::MatrixXd KinematicsDynamics::calcVWerr(Eigen::MatrixXd tar_position, Eigen::MatrixXd curr_position,
                                                         Eigen::MatrixXd tar_orientation, Eigen::MatrixXd curr_orientation)
{
  Eigen::MatrixXd pos_err = tar_position - curr_position;
  Eigen::MatrixXd ori_err1 = curr_orientation.inverse() * tar_orientation;
  Eigen::MatrixXd ori_err2 = curr_orientation * robotis_framework::convertRotToOmega(ori_err1);

  Eigen::MatrixXd err = Eigen::MatrixXd::Zero(6, 1);
  err.block(0, 0, 3, 1) = pos_err;
  err.block(3, 0, 3, 1) = ori_err2;

  return err;
}

bool KinematicsDynamics::inverseKinematics(int to, Eigen::MatrixXd tar_position,
    Eigen::MatrixXd tar_orientation, int max_iter, double ik_err)
{
  bool ik_success     = false;
  bool limit_success  = false;

  forwardKinematics(0);

  std::vector<int> idx = findRoute(to);

  for (int iter = 0; iter < max_iter; iter++)
  {
    Eigen::MatrixXd jacobian = calcJacobian(idx);

    Eigen::MatrixXd curr_position     = link_data_[to]->position_;
    Eigen::MatrixXd curr_orientation  = link_data_[to]->orientation_;

    Eigen::MatrixXd err = calcVWerr(tar_position, curr_position, tar_orientation, curr_orientation);

    if (err.norm() < ik_err)
    {
      ik_success = true;
      break;
    }
    else
      ik_success = false;

    Eigen::MatrixXd jacobian2 = jacobian * jacobian.transpose();
    Eigen::MatrixXd jacobian3 = jacobian.transpose() * jacobian2.inverse();

    Eigen::MatrixXd _delta_angle = jacobian3 * err;

    for (int id = 0; id < idx.size(); id++)
    {
      int joint_num = idx[id];
      link_data_[joint_num]->joint_angle_ += _delta_angle.coeff(id);
    }

    forwardKinematics(0);
  }

  for (int id = 0; id < idx.size(); id++)
  {
    int joint_num = idx[id];

    if (link_data_[joint_num]->joint_angle_ >= link_data_[joint_num]->joint_limit_max_)
    {
      limit_success = false;
      break;
    }
    else if (link_data_[joint_num]->joint_angle_ <= link_data_[joint_num]->joint_limit_min_)
    {
      limit_success = false;
      break;
    }
    else
      limit_success = true;
  }

  if (ik_success == true && limit_success == true)
    return true;
  else
    return false;
}

bool KinematicsDynamics::inverseKinematics(int from, int to, Eigen::MatrixXd tar_position,
                                                      Eigen::MatrixXd tar_orientation, int max_iter, double ik_err)
{
  bool ik_success = false;
  bool limit_success = false;

  forwardKinematics(0);

  std::vector<int> idx = findRoute(from, to);

  for (int iter = 0; iter < max_iter; iter++)
  {
    Eigen::MatrixXd jacobian = calcJacobian(idx);

    Eigen::MatrixXd curr_position     = link_data_[to]->position_;
    Eigen::MatrixXd curr_orientation  = link_data_[to]->orientation_;

    Eigen::MatrixXd err = calcVWerr(tar_position, curr_position, tar_orientation, curr_orientation);

    if (err.norm() < ik_err)
    {
      ik_success = true;
      break;
    }
    else
    {
      ik_success = false;
    }

    Eigen::MatrixXd jacobian2 = jacobian * jacobian.transpose();
    Eigen::MatrixXd jacobian3 = jacobian.transpose() * jacobian2.inverse();

    Eigen::MatrixXd delta_angle = jacobian3 * err;

    for (int id = 0; id < idx.size(); id++)
    {
      int joint_num = idx[id];
      link_data_[joint_num]->joint_angle_ += delta_angle.coeff(id);
    }

    forwardKinematics(0);
  }

  for (int id = 0; id < idx.size(); id++)
  {
    int joint_num = idx[id];

    if (link_data_[joint_num]->joint_angle_ >= link_data_[joint_num]->joint_limit_max_)
    {
      limit_success = false;
      break;
    }
    else if (link_data_[joint_num]->joint_angle_ <= link_data_[joint_num]->joint_limit_min_)
    {
      limit_success = false;
      break;
    }
    else
      limit_success = true;
  }

  if (ik_success == true && limit_success == true)
    return true;
  else
    return false;
}

bool KinematicsDynamics::inverseKinematicsOnlyPosition(int to, Eigen::MatrixXd tar_position,
                                                       int max_iter, double ik_err)
{
  bool ik_success = false;
  bool limit_success = false;

  forwardKinematics(0);

  std::vector<int> idx = findRoute(to);

  for (int iter = 0; iter < max_iter; iter++)
  {
    Eigen::MatrixXd jacobian = calcJacobianOnlyPosition(idx);

    Eigen::MatrixXd curr_position = link_data_[to]->position_;

    Eigen::MatrixXd err = tar_position - curr_position;

    if (err.norm() < ik_err)
    {
      ik_success = true;
      break;
    }
    else
    {
      ik_success = false;
    }

    Eigen::MatrixXd jacobian2 = jacobian * jacobian.transpose();
    Eigen::MatrixXd jacobian3 = jacobian.transpose() * jacobian2.inverse();

    Eigen::MatrixXd delta_angle = jacobian3 * err;

    for (int id = 0; id < idx.size(); id++)
    {
      int joint_num = idx[id];
      link_data_[joint_num]->joint_angle_ += delta_angle.coeff(id);
    }

    forwardKinematics(0);
  }

  for (int id = 0; id < idx.size(); id++)
  {
    int joint_num = idx[id];

    if (link_data_[joint_num]->joint_angle_ >= link_data_[joint_num]->joint_limit_max_)
    {
      limit_success = false;
      break;
    }
    else if (link_data_[joint_num]->joint_angle_ <= link_data_[joint_num]->joint_limit_min_)
    {
      limit_success = false;
      break;
    }
    else
      limit_success = true;
  }

  if (ik_success == true && limit_success == true)
    return true;
  else
    return false;
}

}
