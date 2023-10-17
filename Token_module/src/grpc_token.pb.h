// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: grpc_token.proto

#ifndef GOOGLE_PROTOBUF_INCLUDED_grpc_5ftoken_2eproto
#define GOOGLE_PROTOBUF_INCLUDED_grpc_5ftoken_2eproto

#include <limits>
#include <string>

#include <google/protobuf/port_def.inc>
#if PROTOBUF_VERSION < 3021000
#error This file was generated by a newer version of protoc which is
#error incompatible with your Protocol Buffer headers. Please update
#error your headers.
#endif
#if 3021012 < PROTOBUF_MIN_PROTOC_VERSION
#error This file was generated by an older version of protoc which is
#error incompatible with your Protocol Buffer headers. Please
#error regenerate this file with a newer version of protoc.
#endif

#include <google/protobuf/port_undef.inc>
#include <google/protobuf/io/coded_stream.h>
#include <google/protobuf/arena.h>
#include <google/protobuf/arenastring.h>
#include <google/protobuf/generated_message_util.h>
#include <google/protobuf/metadata_lite.h>
#include <google/protobuf/generated_message_reflection.h>
#include <google/protobuf/message.h>
#include <google/protobuf/repeated_field.h>  // IWYU pragma: export
#include <google/protobuf/extension_set.h>  // IWYU pragma: export
#include <google/protobuf/unknown_field_set.h>
#include "token.pb.h"
// @@protoc_insertion_point(includes)
#include <google/protobuf/port_def.inc>
#define PROTOBUF_INTERNAL_EXPORT_grpc_5ftoken_2eproto
PROTOBUF_NAMESPACE_OPEN
namespace internal {
class AnyMetadata;
}  // namespace internal
PROTOBUF_NAMESPACE_CLOSE

// Internal implementation detail -- do not use these members.
struct TableStruct_grpc_5ftoken_2eproto {
  static const uint32_t offsets[];
};
extern const ::PROTOBUF_NAMESPACE_ID::internal::DescriptorTable descriptor_table_grpc_5ftoken_2eproto;
namespace tokengrpc {
class List_tokens;
struct List_tokensDefaultTypeInternal;
extern List_tokensDefaultTypeInternal _List_tokens_default_instance_;
class Node_id;
struct Node_idDefaultTypeInternal;
extern Node_idDefaultTypeInternal _Node_id_default_instance_;
class Value;
struct ValueDefaultTypeInternal;
extern ValueDefaultTypeInternal _Value_default_instance_;
}  // namespace tokengrpc
PROTOBUF_NAMESPACE_OPEN
template<> ::tokengrpc::List_tokens* Arena::CreateMaybeMessage<::tokengrpc::List_tokens>(Arena*);
template<> ::tokengrpc::Node_id* Arena::CreateMaybeMessage<::tokengrpc::Node_id>(Arena*);
template<> ::tokengrpc::Value* Arena::CreateMaybeMessage<::tokengrpc::Value>(Arena*);
PROTOBUF_NAMESPACE_CLOSE
namespace tokengrpc {

// ===================================================================

class Value final :
    public ::PROTOBUF_NAMESPACE_ID::Message /* @@protoc_insertion_point(class_definition:tokengrpc.Value) */ {
 public:
  inline Value() : Value(nullptr) {}
  ~Value() override;
  explicit PROTOBUF_CONSTEXPR Value(::PROTOBUF_NAMESPACE_ID::internal::ConstantInitialized);

  Value(const Value& from);
  Value(Value&& from) noexcept
    : Value() {
    *this = ::std::move(from);
  }

  inline Value& operator=(const Value& from) {
    CopyFrom(from);
    return *this;
  }
  inline Value& operator=(Value&& from) noexcept {
    if (this == &from) return *this;
    if (GetOwningArena() == from.GetOwningArena()
  #ifdef PROTOBUF_FORCE_COPY_IN_MOVE
        && GetOwningArena() != nullptr
  #endif  // !PROTOBUF_FORCE_COPY_IN_MOVE
    ) {
      InternalSwap(&from);
    } else {
      CopyFrom(from);
    }
    return *this;
  }

  static const ::PROTOBUF_NAMESPACE_ID::Descriptor* descriptor() {
    return GetDescriptor();
  }
  static const ::PROTOBUF_NAMESPACE_ID::Descriptor* GetDescriptor() {
    return default_instance().GetMetadata().descriptor;
  }
  static const ::PROTOBUF_NAMESPACE_ID::Reflection* GetReflection() {
    return default_instance().GetMetadata().reflection;
  }
  static const Value& default_instance() {
    return *internal_default_instance();
  }
  static inline const Value* internal_default_instance() {
    return reinterpret_cast<const Value*>(
               &_Value_default_instance_);
  }
  static constexpr int kIndexInFileMessages =
    0;

  friend void swap(Value& a, Value& b) {
    a.Swap(&b);
  }
  inline void Swap(Value* other) {
    if (other == this) return;
  #ifdef PROTOBUF_FORCE_COPY_IN_SWAP
    if (GetOwningArena() != nullptr &&
        GetOwningArena() == other->GetOwningArena()) {
   #else  // PROTOBUF_FORCE_COPY_IN_SWAP
    if (GetOwningArena() == other->GetOwningArena()) {
  #endif  // !PROTOBUF_FORCE_COPY_IN_SWAP
      InternalSwap(other);
    } else {
      ::PROTOBUF_NAMESPACE_ID::internal::GenericSwap(this, other);
    }
  }
  void UnsafeArenaSwap(Value* other) {
    if (other == this) return;
    GOOGLE_DCHECK(GetOwningArena() == other->GetOwningArena());
    InternalSwap(other);
  }

  // implements Message ----------------------------------------------

  Value* New(::PROTOBUF_NAMESPACE_ID::Arena* arena = nullptr) const final {
    return CreateMaybeMessage<Value>(arena);
  }
  using ::PROTOBUF_NAMESPACE_ID::Message::CopyFrom;
  void CopyFrom(const Value& from);
  using ::PROTOBUF_NAMESPACE_ID::Message::MergeFrom;
  void MergeFrom( const Value& from) {
    Value::MergeImpl(*this, from);
  }
  private:
  static void MergeImpl(::PROTOBUF_NAMESPACE_ID::Message& to_msg, const ::PROTOBUF_NAMESPACE_ID::Message& from_msg);
  public:
  PROTOBUF_ATTRIBUTE_REINITIALIZES void Clear() final;
  bool IsInitialized() const final;

  size_t ByteSizeLong() const final;
  const char* _InternalParse(const char* ptr, ::PROTOBUF_NAMESPACE_ID::internal::ParseContext* ctx) final;
  uint8_t* _InternalSerialize(
      uint8_t* target, ::PROTOBUF_NAMESPACE_ID::io::EpsCopyOutputStream* stream) const final;
  int GetCachedSize() const final { return _impl_._cached_size_.Get(); }

  private:
  void SharedCtor(::PROTOBUF_NAMESPACE_ID::Arena* arena, bool is_message_owned);
  void SharedDtor();
  void SetCachedSize(int size) const final;
  void InternalSwap(Value* other);

  private:
  friend class ::PROTOBUF_NAMESPACE_ID::internal::AnyMetadata;
  static ::PROTOBUF_NAMESPACE_ID::StringPiece FullMessageName() {
    return "tokengrpc.Value";
  }
  protected:
  explicit Value(::PROTOBUF_NAMESPACE_ID::Arena* arena,
                       bool is_message_owned = false);
  public:

  static const ClassData _class_data_;
  const ::PROTOBUF_NAMESPACE_ID::Message::ClassData*GetClassData() const final;

  ::PROTOBUF_NAMESPACE_ID::Metadata GetMetadata() const final;

  // nested types ----------------------------------------------------

  // accessors -------------------------------------------------------

  enum : int {
    kValueFieldNumber = 1,
  };
  // string value = 1;
  void clear_value();
  const std::string& value() const;
  template <typename ArgT0 = const std::string&, typename... ArgT>
  void set_value(ArgT0&& arg0, ArgT... args);
  std::string* mutable_value();
  PROTOBUF_NODISCARD std::string* release_value();
  void set_allocated_value(std::string* value);
  private:
  const std::string& _internal_value() const;
  inline PROTOBUF_ALWAYS_INLINE void _internal_set_value(const std::string& value);
  std::string* _internal_mutable_value();
  public:

  // @@protoc_insertion_point(class_scope:tokengrpc.Value)
 private:
  class _Internal;

  template <typename T> friend class ::PROTOBUF_NAMESPACE_ID::Arena::InternalHelper;
  typedef void InternalArenaConstructable_;
  typedef void DestructorSkippable_;
  struct Impl_ {
    ::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr value_;
    mutable ::PROTOBUF_NAMESPACE_ID::internal::CachedSize _cached_size_;
  };
  union { Impl_ _impl_; };
  friend struct ::TableStruct_grpc_5ftoken_2eproto;
};
// -------------------------------------------------------------------

class Node_id final :
    public ::PROTOBUF_NAMESPACE_ID::Message /* @@protoc_insertion_point(class_definition:tokengrpc.Node_id) */ {
 public:
  inline Node_id() : Node_id(nullptr) {}
  ~Node_id() override;
  explicit PROTOBUF_CONSTEXPR Node_id(::PROTOBUF_NAMESPACE_ID::internal::ConstantInitialized);

  Node_id(const Node_id& from);
  Node_id(Node_id&& from) noexcept
    : Node_id() {
    *this = ::std::move(from);
  }

  inline Node_id& operator=(const Node_id& from) {
    CopyFrom(from);
    return *this;
  }
  inline Node_id& operator=(Node_id&& from) noexcept {
    if (this == &from) return *this;
    if (GetOwningArena() == from.GetOwningArena()
  #ifdef PROTOBUF_FORCE_COPY_IN_MOVE
        && GetOwningArena() != nullptr
  #endif  // !PROTOBUF_FORCE_COPY_IN_MOVE
    ) {
      InternalSwap(&from);
    } else {
      CopyFrom(from);
    }
    return *this;
  }

  static const ::PROTOBUF_NAMESPACE_ID::Descriptor* descriptor() {
    return GetDescriptor();
  }
  static const ::PROTOBUF_NAMESPACE_ID::Descriptor* GetDescriptor() {
    return default_instance().GetMetadata().descriptor;
  }
  static const ::PROTOBUF_NAMESPACE_ID::Reflection* GetReflection() {
    return default_instance().GetMetadata().reflection;
  }
  static const Node_id& default_instance() {
    return *internal_default_instance();
  }
  static inline const Node_id* internal_default_instance() {
    return reinterpret_cast<const Node_id*>(
               &_Node_id_default_instance_);
  }
  static constexpr int kIndexInFileMessages =
    1;

  friend void swap(Node_id& a, Node_id& b) {
    a.Swap(&b);
  }
  inline void Swap(Node_id* other) {
    if (other == this) return;
  #ifdef PROTOBUF_FORCE_COPY_IN_SWAP
    if (GetOwningArena() != nullptr &&
        GetOwningArena() == other->GetOwningArena()) {
   #else  // PROTOBUF_FORCE_COPY_IN_SWAP
    if (GetOwningArena() == other->GetOwningArena()) {
  #endif  // !PROTOBUF_FORCE_COPY_IN_SWAP
      InternalSwap(other);
    } else {
      ::PROTOBUF_NAMESPACE_ID::internal::GenericSwap(this, other);
    }
  }
  void UnsafeArenaSwap(Node_id* other) {
    if (other == this) return;
    GOOGLE_DCHECK(GetOwningArena() == other->GetOwningArena());
    InternalSwap(other);
  }

  // implements Message ----------------------------------------------

  Node_id* New(::PROTOBUF_NAMESPACE_ID::Arena* arena = nullptr) const final {
    return CreateMaybeMessage<Node_id>(arena);
  }
  using ::PROTOBUF_NAMESPACE_ID::Message::CopyFrom;
  void CopyFrom(const Node_id& from);
  using ::PROTOBUF_NAMESPACE_ID::Message::MergeFrom;
  void MergeFrom( const Node_id& from) {
    Node_id::MergeImpl(*this, from);
  }
  private:
  static void MergeImpl(::PROTOBUF_NAMESPACE_ID::Message& to_msg, const ::PROTOBUF_NAMESPACE_ID::Message& from_msg);
  public:
  PROTOBUF_ATTRIBUTE_REINITIALIZES void Clear() final;
  bool IsInitialized() const final;

  size_t ByteSizeLong() const final;
  const char* _InternalParse(const char* ptr, ::PROTOBUF_NAMESPACE_ID::internal::ParseContext* ctx) final;
  uint8_t* _InternalSerialize(
      uint8_t* target, ::PROTOBUF_NAMESPACE_ID::io::EpsCopyOutputStream* stream) const final;
  int GetCachedSize() const final { return _impl_._cached_size_.Get(); }

  private:
  void SharedCtor(::PROTOBUF_NAMESPACE_ID::Arena* arena, bool is_message_owned);
  void SharedDtor();
  void SetCachedSize(int size) const final;
  void InternalSwap(Node_id* other);

  private:
  friend class ::PROTOBUF_NAMESPACE_ID::internal::AnyMetadata;
  static ::PROTOBUF_NAMESPACE_ID::StringPiece FullMessageName() {
    return "tokengrpc.Node_id";
  }
  protected:
  explicit Node_id(::PROTOBUF_NAMESPACE_ID::Arena* arena,
                       bool is_message_owned = false);
  public:

  static const ClassData _class_data_;
  const ::PROTOBUF_NAMESPACE_ID::Message::ClassData*GetClassData() const final;

  ::PROTOBUF_NAMESPACE_ID::Metadata GetMetadata() const final;

  // nested types ----------------------------------------------------

  // accessors -------------------------------------------------------

  enum : int {
    kIdFieldNumber = 1,
  };
  // int32 id = 1;
  void clear_id();
  int32_t id() const;
  void set_id(int32_t value);
  private:
  int32_t _internal_id() const;
  void _internal_set_id(int32_t value);
  public:

  // @@protoc_insertion_point(class_scope:tokengrpc.Node_id)
 private:
  class _Internal;

  template <typename T> friend class ::PROTOBUF_NAMESPACE_ID::Arena::InternalHelper;
  typedef void InternalArenaConstructable_;
  typedef void DestructorSkippable_;
  struct Impl_ {
    int32_t id_;
    mutable ::PROTOBUF_NAMESPACE_ID::internal::CachedSize _cached_size_;
  };
  union { Impl_ _impl_; };
  friend struct ::TableStruct_grpc_5ftoken_2eproto;
};
// -------------------------------------------------------------------

class List_tokens final :
    public ::PROTOBUF_NAMESPACE_ID::Message /* @@protoc_insertion_point(class_definition:tokengrpc.List_tokens) */ {
 public:
  inline List_tokens() : List_tokens(nullptr) {}
  ~List_tokens() override;
  explicit PROTOBUF_CONSTEXPR List_tokens(::PROTOBUF_NAMESPACE_ID::internal::ConstantInitialized);

  List_tokens(const List_tokens& from);
  List_tokens(List_tokens&& from) noexcept
    : List_tokens() {
    *this = ::std::move(from);
  }

  inline List_tokens& operator=(const List_tokens& from) {
    CopyFrom(from);
    return *this;
  }
  inline List_tokens& operator=(List_tokens&& from) noexcept {
    if (this == &from) return *this;
    if (GetOwningArena() == from.GetOwningArena()
  #ifdef PROTOBUF_FORCE_COPY_IN_MOVE
        && GetOwningArena() != nullptr
  #endif  // !PROTOBUF_FORCE_COPY_IN_MOVE
    ) {
      InternalSwap(&from);
    } else {
      CopyFrom(from);
    }
    return *this;
  }

  static const ::PROTOBUF_NAMESPACE_ID::Descriptor* descriptor() {
    return GetDescriptor();
  }
  static const ::PROTOBUF_NAMESPACE_ID::Descriptor* GetDescriptor() {
    return default_instance().GetMetadata().descriptor;
  }
  static const ::PROTOBUF_NAMESPACE_ID::Reflection* GetReflection() {
    return default_instance().GetMetadata().reflection;
  }
  static const List_tokens& default_instance() {
    return *internal_default_instance();
  }
  static inline const List_tokens* internal_default_instance() {
    return reinterpret_cast<const List_tokens*>(
               &_List_tokens_default_instance_);
  }
  static constexpr int kIndexInFileMessages =
    2;

  friend void swap(List_tokens& a, List_tokens& b) {
    a.Swap(&b);
  }
  inline void Swap(List_tokens* other) {
    if (other == this) return;
  #ifdef PROTOBUF_FORCE_COPY_IN_SWAP
    if (GetOwningArena() != nullptr &&
        GetOwningArena() == other->GetOwningArena()) {
   #else  // PROTOBUF_FORCE_COPY_IN_SWAP
    if (GetOwningArena() == other->GetOwningArena()) {
  #endif  // !PROTOBUF_FORCE_COPY_IN_SWAP
      InternalSwap(other);
    } else {
      ::PROTOBUF_NAMESPACE_ID::internal::GenericSwap(this, other);
    }
  }
  void UnsafeArenaSwap(List_tokens* other) {
    if (other == this) return;
    GOOGLE_DCHECK(GetOwningArena() == other->GetOwningArena());
    InternalSwap(other);
  }

  // implements Message ----------------------------------------------

  List_tokens* New(::PROTOBUF_NAMESPACE_ID::Arena* arena = nullptr) const final {
    return CreateMaybeMessage<List_tokens>(arena);
  }
  using ::PROTOBUF_NAMESPACE_ID::Message::CopyFrom;
  void CopyFrom(const List_tokens& from);
  using ::PROTOBUF_NAMESPACE_ID::Message::MergeFrom;
  void MergeFrom( const List_tokens& from) {
    List_tokens::MergeImpl(*this, from);
  }
  private:
  static void MergeImpl(::PROTOBUF_NAMESPACE_ID::Message& to_msg, const ::PROTOBUF_NAMESPACE_ID::Message& from_msg);
  public:
  PROTOBUF_ATTRIBUTE_REINITIALIZES void Clear() final;
  bool IsInitialized() const final;

  size_t ByteSizeLong() const final;
  const char* _InternalParse(const char* ptr, ::PROTOBUF_NAMESPACE_ID::internal::ParseContext* ctx) final;
  uint8_t* _InternalSerialize(
      uint8_t* target, ::PROTOBUF_NAMESPACE_ID::io::EpsCopyOutputStream* stream) const final;
  int GetCachedSize() const final { return _impl_._cached_size_.Get(); }

  private:
  void SharedCtor(::PROTOBUF_NAMESPACE_ID::Arena* arena, bool is_message_owned);
  void SharedDtor();
  void SetCachedSize(int size) const final;
  void InternalSwap(List_tokens* other);

  private:
  friend class ::PROTOBUF_NAMESPACE_ID::internal::AnyMetadata;
  static ::PROTOBUF_NAMESPACE_ID::StringPiece FullMessageName() {
    return "tokengrpc.List_tokens";
  }
  protected:
  explicit List_tokens(::PROTOBUF_NAMESPACE_ID::Arena* arena,
                       bool is_message_owned = false);
  public:

  static const ClassData _class_data_;
  const ::PROTOBUF_NAMESPACE_ID::Message::ClassData*GetClassData() const final;

  ::PROTOBUF_NAMESPACE_ID::Metadata GetMetadata() const final;

  // nested types ----------------------------------------------------

  // accessors -------------------------------------------------------

  enum : int {
    kTokensFieldNumber = 1,
  };
  // repeated .token.Token tokens = 1;
  int tokens_size() const;
  private:
  int _internal_tokens_size() const;
  public:
  void clear_tokens();
  ::token::Token* mutable_tokens(int index);
  ::PROTOBUF_NAMESPACE_ID::RepeatedPtrField< ::token::Token >*
      mutable_tokens();
  private:
  const ::token::Token& _internal_tokens(int index) const;
  ::token::Token* _internal_add_tokens();
  public:
  const ::token::Token& tokens(int index) const;
  ::token::Token* add_tokens();
  const ::PROTOBUF_NAMESPACE_ID::RepeatedPtrField< ::token::Token >&
      tokens() const;

  // @@protoc_insertion_point(class_scope:tokengrpc.List_tokens)
 private:
  class _Internal;

  template <typename T> friend class ::PROTOBUF_NAMESPACE_ID::Arena::InternalHelper;
  typedef void InternalArenaConstructable_;
  typedef void DestructorSkippable_;
  struct Impl_ {
    ::PROTOBUF_NAMESPACE_ID::RepeatedPtrField< ::token::Token > tokens_;
    mutable ::PROTOBUF_NAMESPACE_ID::internal::CachedSize _cached_size_;
  };
  union { Impl_ _impl_; };
  friend struct ::TableStruct_grpc_5ftoken_2eproto;
};
// ===================================================================


// ===================================================================

#ifdef __GNUC__
  #pragma GCC diagnostic push
  #pragma GCC diagnostic ignored "-Wstrict-aliasing"
#endif  // __GNUC__
// Value

// string value = 1;
inline void Value::clear_value() {
  _impl_.value_.ClearToEmpty();
}
inline const std::string& Value::value() const {
  // @@protoc_insertion_point(field_get:tokengrpc.Value.value)
  return _internal_value();
}
template <typename ArgT0, typename... ArgT>
inline PROTOBUF_ALWAYS_INLINE
void Value::set_value(ArgT0&& arg0, ArgT... args) {
 
 _impl_.value_.Set(static_cast<ArgT0 &&>(arg0), args..., GetArenaForAllocation());
  // @@protoc_insertion_point(field_set:tokengrpc.Value.value)
}
inline std::string* Value::mutable_value() {
  std::string* _s = _internal_mutable_value();
  // @@protoc_insertion_point(field_mutable:tokengrpc.Value.value)
  return _s;
}
inline const std::string& Value::_internal_value() const {
  return _impl_.value_.Get();
}
inline void Value::_internal_set_value(const std::string& value) {
  
  _impl_.value_.Set(value, GetArenaForAllocation());
}
inline std::string* Value::_internal_mutable_value() {
  
  return _impl_.value_.Mutable(GetArenaForAllocation());
}
inline std::string* Value::release_value() {
  // @@protoc_insertion_point(field_release:tokengrpc.Value.value)
  return _impl_.value_.Release();
}
inline void Value::set_allocated_value(std::string* value) {
  if (value != nullptr) {
    
  } else {
    
  }
  _impl_.value_.SetAllocated(value, GetArenaForAllocation());
#ifdef PROTOBUF_FORCE_COPY_DEFAULT_STRING
  if (_impl_.value_.IsDefault()) {
    _impl_.value_.Set("", GetArenaForAllocation());
  }
#endif // PROTOBUF_FORCE_COPY_DEFAULT_STRING
  // @@protoc_insertion_point(field_set_allocated:tokengrpc.Value.value)
}

// -------------------------------------------------------------------

// Node_id

// int32 id = 1;
inline void Node_id::clear_id() {
  _impl_.id_ = 0;
}
inline int32_t Node_id::_internal_id() const {
  return _impl_.id_;
}
inline int32_t Node_id::id() const {
  // @@protoc_insertion_point(field_get:tokengrpc.Node_id.id)
  return _internal_id();
}
inline void Node_id::_internal_set_id(int32_t value) {
  
  _impl_.id_ = value;
}
inline void Node_id::set_id(int32_t value) {
  _internal_set_id(value);
  // @@protoc_insertion_point(field_set:tokengrpc.Node_id.id)
}

// -------------------------------------------------------------------

// List_tokens

// repeated .token.Token tokens = 1;
inline int List_tokens::_internal_tokens_size() const {
  return _impl_.tokens_.size();
}
inline int List_tokens::tokens_size() const {
  return _internal_tokens_size();
}
inline ::token::Token* List_tokens::mutable_tokens(int index) {
  // @@protoc_insertion_point(field_mutable:tokengrpc.List_tokens.tokens)
  return _impl_.tokens_.Mutable(index);
}
inline ::PROTOBUF_NAMESPACE_ID::RepeatedPtrField< ::token::Token >*
List_tokens::mutable_tokens() {
  // @@protoc_insertion_point(field_mutable_list:tokengrpc.List_tokens.tokens)
  return &_impl_.tokens_;
}
inline const ::token::Token& List_tokens::_internal_tokens(int index) const {
  return _impl_.tokens_.Get(index);
}
inline const ::token::Token& List_tokens::tokens(int index) const {
  // @@protoc_insertion_point(field_get:tokengrpc.List_tokens.tokens)
  return _internal_tokens(index);
}
inline ::token::Token* List_tokens::_internal_add_tokens() {
  return _impl_.tokens_.Add();
}
inline ::token::Token* List_tokens::add_tokens() {
  ::token::Token* _add = _internal_add_tokens();
  // @@protoc_insertion_point(field_add:tokengrpc.List_tokens.tokens)
  return _add;
}
inline const ::PROTOBUF_NAMESPACE_ID::RepeatedPtrField< ::token::Token >&
List_tokens::tokens() const {
  // @@protoc_insertion_point(field_list:tokengrpc.List_tokens.tokens)
  return _impl_.tokens_;
}

#ifdef __GNUC__
  #pragma GCC diagnostic pop
#endif  // __GNUC__
// -------------------------------------------------------------------

// -------------------------------------------------------------------


// @@protoc_insertion_point(namespace_scope)

}  // namespace tokengrpc

// @@protoc_insertion_point(global_scope)

#include <google/protobuf/port_undef.inc>
#endif  // GOOGLE_PROTOBUF_INCLUDED_GOOGLE_PROTOBUF_INCLUDED_grpc_5ftoken_2eproto