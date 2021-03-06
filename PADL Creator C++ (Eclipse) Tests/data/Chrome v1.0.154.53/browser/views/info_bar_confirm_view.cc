// Copyright (c) 2006-2008 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#include "chrome/browser/views/info_bar_confirm_view.h"
#include "chrome/browser/views/standard_layout.h"
#include "chrome/common/l10n_util.h"

#include "generated_resources.h"

InfoBarConfirmView::InfoBarConfirmView(const std::wstring& message)
    : ok_button_(new views::NativeButton(l10n_util::GetString(IDS_OK))),
      cancel_button_(new views::NativeButton(l10n_util::GetString(IDS_CANCEL))),
      initialized_(false),
      InfoBarMessageView(message) {
  ok_button_->SetListener(this);
  cancel_button_->SetListener(this);
}

InfoBarConfirmView::~InfoBarConfirmView() {}

void InfoBarConfirmView::OKButtonPressed() {
  // Delete and close this view by default.
  BeginClose();
}

void InfoBarConfirmView::CancelButtonPressed() {
  // Delete and close this view by default.
  BeginClose();
}

void InfoBarConfirmView::ButtonPressed(views::NativeButton* sender) {
  // If you close the bar from one of these functions, make sure to use
  // BeginClose() - Close() could delete us and cause the rest of the
  // function to go bananas.
  if (sender == ok_button_)
    OKButtonPressed();
  else if (sender == cancel_button_)
    CancelButtonPressed();

  // Disable our buttons - we only want to allow users to press one, and
  // leaving them enabled could allow further interaction during the close
  // animation.
  if (ok_button_)
    ok_button_->SetEnabled(false);
  if (cancel_button_)
    cancel_button_->SetEnabled(false);
}

void InfoBarConfirmView::SetOKButtonLabel(const std::wstring& label) {
  if (ok_button_) {
    ok_button_->SetLabel(label);
    ok_button_->SetAccessibleName(label);
    Layout();
  }
}

void InfoBarConfirmView::SetCancelButtonLabel(const std::wstring& label) {
  if (cancel_button_) {
    cancel_button_->SetLabel(label);
    cancel_button_->SetAccessibleName(label);
    Layout();
  }
}

void InfoBarConfirmView::RemoveCancelButton() {
  if (cancel_button_) {
    RemoveChildView(cancel_button_);
    delete cancel_button_;
    cancel_button_ = NULL;
    Layout();
  }
}

void InfoBarConfirmView::RemoveOKButton() {
  if (ok_button_) {
    RemoveChildView(ok_button_);
    delete ok_button_;
    ok_button_ = NULL;
    Layout();
  }
}

bool InfoBarConfirmView::GetAccessibleRole(VARIANT* role) {
  DCHECK(role);

  role->vt = VT_I4;
  role->lVal = ROLE_SYSTEM_GROUPING;
  return true;
}

// Overridden from views::View:
void InfoBarConfirmView::ViewHierarchyChanged(bool is_add, views::View* parent,
                                              views::View* child) {
  if (is_add && !initialized_ && GetContainer()) {
    initialized_ = true;
    Init();
  }
}

void InfoBarConfirmView::Init() {
  // Need to NULL check since the buttons may have been removed by the Remove*
  // functions above.
  if (cancel_button_)
    AddChildViewTrailing(cancel_button_, kRelatedButtonHSpacing);
  if (ok_button_)
    AddChildViewTrailing(ok_button_);
}
